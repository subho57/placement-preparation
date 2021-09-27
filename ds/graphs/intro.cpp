/**
 * @file intro.cpp
 * @author Subhankar Pal (developer.subho57@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @input A : n, m where n = no of nodes, and m = total no of edges
 * @input B : m times u, v where u, v are the nodes
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // declare the adjacency matrix
    int adj_mat[n+1][n+1];
    memset(adj_mat, 0, sizeof(adj_mat));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }

    // declare the adjacency list
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

}
