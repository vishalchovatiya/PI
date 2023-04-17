#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG(X) cout << #X << " = " << X << endl;
#define ALL(X) begin(X), end(X)

void dfs(uint64_t u, const vector<vector<uint64_t>> &graph,
         vector<bool> &visited, vector<uint64_t> &cut_vertices,
         int64_t parent = -1, uint64_t time = 0) {

    static vector<uint64_t> visit_time(graph.size(), 0);
    static vector<uint64_t> lowest_time(graph.size(), 0);

    visited[u] = true;
    visit_time[u] = lowest_time[u] = time;
    uint64_t children = 0;

    for (auto &&v : graph[u]) {
        if (parent == v) continue; // ignore parent
        if (visited[v]) {          // back edge
            lowest_time[u] = min(lowest_time[u], visit_time[v]);
        } else { // tree edge
            dfs(v, graph, visited, cut_vertices, u, time + 1);
            lowest_time[u] = min(lowest_time[u], lowest_time[v]);

            if (parent != -1 &&
                lowest_time[v] > visit_time[u]) { // Cut vertices property
                cut_vertices.push_back(u);
            }
            ++children;
        }
    }

    if (parent == -1 && children > 1) { // Cut vertices property for root
        cut_vertices.push_back(u);
    }
}

vector<uint64_t> find_cut_vertices(const vector<vector<uint64_t>> &graph) {
    vector<uint64_t> cut_vertices;
    vector<bool> visited(graph.size(), false);

    for (uint64_t u = 0; u < graph.size(); ++u)
        if (!visited[u]) dfs(u, graph, visited, cut_vertices);

    return cut_vertices;
}

int main() {
    uint64_t n, m;
    cin >> n >> m;

    // Create graph
    n += 1; // vertex can start from 0 or 1
    vector<vector<uint64_t>> graph(n);
    for (uint64_t i = 0; i < m; ++i) {
        uint64_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Find cut vertices
    auto cut_vertices = find_cut_vertices(graph);
    sort(ALL(cut_vertices));
    cout << cut_vertices.size() << endl;
    for (auto &&v : cut_vertices) cout << v << " ";

    return 0;
}

/*
/CP/build/main < ../input.txt > ../output.txt

Test Case 1:
4 3
1 2
2 3
3 4

2
2 3


Test Case 2:
5 5
1 0
0 2
2 1
0 3
3 4

2
0 3


Test Case 3:
4 3
0 1
1 2
2 3


2
1 2
 */
