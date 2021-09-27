/**
 * @file dfs.cpp
 * @author Subhankar Pal (developer.subho57@gmail.com)
 * @brief Graph Traversal using DFS
 * @version 0.1
 * @date 2021-09-27
 * @copyright Copyright (c) 2021
 */

/**
 * @input A : n, m where n = no of nodes, and m = total no of edges
 * @input B : m times u, v where u, v are the nodes
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // declare the adjacency list
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // declare the visited array
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // declare the stack
            stack<int> st;

            // push the first node to the stack
            st.push(i);

            // while the stack is not empty
            while (!st.empty())
            {
                // pop the top element from the stack
                int curr = st.top();
                st.pop();

                // if the current node is not visited
                if (!visited[curr])
                {
                    // mark it as visited
                    visited[curr] = true;

                    // push all the adjacent nodes to the stack
                    for (int i = 0; i < adj[curr].size(); i++)
                    {
                        st.push(adj[curr][i]);
                    }
                }
            }
        }
    }

    // print the visited array
    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }

    return 0;
}
