#include <iostream>
#include <algorithm>
#include <vector>
#include <utils.hpp>

using namespace std;

#define DEBUG(X) cout << #X << " = " << X << endl;
#define ALL(X) begin(X), end(X)

void dfs(uint64_t u, const vector<vector<uint64_t>> &graph,
         vector<bool> &visited, vector<uint64_t> &connected_components) {
    visited[u] = true;
    connected_components.push_back(u);

    for (auto &&v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph, visited, connected_components);
        }
    }
}

auto find_weakly_connected_components(const vector<vector<uint64_t>> &graph) {
    vector<vector<uint64_t>> connected_components;
    vector<bool> visited(graph.size(), false);

    for (uint64_t u = 0; u < graph.size(); ++u){
        if (!visited[u]) {
            vector<uint64_t> cc;
            dfs(u, graph, visited, cc);
            sort(ALL(cc));
            connected_components.push_back(cc);
        }
    }

    auto by_smallest_vertex = [](auto &a, auto &b) {return a[0] < b[0];};
    sort(ALL(connected_components), by_smallest_vertex);

    return connected_components;
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
        graph[v].push_back(u); // underlying undirected graph
    }

    // Find connected components
    auto connected_components = find_weakly_connected_components(graph);
    
    // if graph doesnt have vertex 0, then remove it
    if (graph[0].size() == 0) {
        connected_components.erase(connected_components.begin());
    }

    cout << connected_components.size() << endl;
    for (auto &&cc : connected_components) {
        cout << cc.size() << " ";
        for (auto &&v : cc) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
/CP/build/main < ../input.txt > ../output.txt

Test Case 1:
6 4
1 5
3 6
5 4
4 1

3
3 1 4 5 
1 2 
2 3 6 

Test Case 2:
6 5
0 1
0 2
3 1
3 2
4 5

3
4 0 1 2 3 
2 4 5 
1 6

Test Case 3:

 */
