#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG(X) cout << #X << " = " << X << endl;
#define ALL(X) begin(X), end(X)

// Single source shortest path Bellman-Ford algorithm
// Time complexity: O(VE)
// Space complexity: O(V)
tuple<vector<uint64_t>, vector<uint64_t>> 
sssp_bellman_ford(uint64_t s, const vector<vector<pair<uint64_t, uint64_t>>> &graph) {
    uint64_t n = graph.size();
    vector<uint64_t>    dist(n, UINT64_MAX);
    vector<uint64_t>    parent(n, UINT64_MAX);

    dist[s] = 0;
    parent[s] = s;

    for (uint64_t i = 0; i < n - 1; ++i) {
        for (uint64_t u = 0; u < n; ++u) {
            for (auto &&[v, w] : graph[u]) {
                if (dist[u] != UINT64_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
    return {dist, parent};
}

// Single source longest path Bellman-Ford algorithm
// Time complexity: O(VE)
// Space complexity: O(V)
tuple<vector<int64_t>, vector<uint64_t>>
sslp_bellman_ford(uint64_t s, const vector<vector<pair<uint64_t, int64_t>>> &graph) {
    uint64_t n = graph.size();
    vector<int64_t>     dist(n, INT64_MIN);
    vector<uint64_t>    parent(n, UINT64_MAX);

    dist[s] = 0;
    parent[s] = s;

    for (uint64_t i = 0; i < n - 1; ++i) {
        for (uint64_t u = 0; u < n; ++u) {
            for (auto &&[v, w] : graph[u]) {
                if (dist[u] != INT64_MIN && dist[u] + w > dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
    return {dist, parent};
}


int main() {
    uint64_t n, m;
    cin >> n >> m;

    // Create weighted graph
    n += 1; // vertex can start from 0 or 1
    vector<vector<pair<uint64_t, uint64_t>>> graph(n);
    for (uint64_t i = 0; i < m; ++i) {
        uint64_t u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // Single source shortest path
    auto [dist, parent] = sssp_bellman_ford(0, graph);

    // Print shortest path
    for (uint64_t u = 0; u < n; ++u) {
        cout << "Shortest path from 0 to " << u << ": ";
        if (dist[u] == UINT64_MAX) {
            cout << "No path" << endl;
        } else {
            vector<uint64_t> path;
            for (uint64_t v = u; v != parent[v]; v = parent[v]) {
                path.push_back(v);
            }
            path.push_back(0);
            reverse(ALL(path));
            for (auto &&v : path) cout << v << " ";
            cout << endl;
        }
    } 

    return 0;
}

/*
/CP/build/main < ../input.txt > ../output.txt

Test Case 1:
4 5
0 1 2
0 2 4
1 2 1
1 3 5
2 3 3


Test Case 2:
3 3
0 1 5
0 2 3
1 2 1


Test Case 3:
5 7
0 1 4
0 2 1
1 2 2
1 3 5
2 3 8
2 4 10
3 4 6

Test Case 4:
6 9
0 1 3
0 3 6
0 4 2
1 2 1
1 3 4
2 3 2
2 4 3
3 4 1
4 5 4
 */
