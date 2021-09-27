/**
 * @file bfs.cpp
 * @author Subhankar Pal (developer.subho57@gmail.com)
 * @brief Graph Traversal using BFS
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

    for (int i = 1; i <= n; i++) // start from 1 as 0 is the source node
    {
        if (!visited[i])
        {
            // declare the queue
            queue<int> q;

            // enqueue the source node
            q.push(i);
            visited[i] = true;

            // while the queue is not empty
            while (!q.empty())
            {
                // dequeue the front node
                int u = q.front();
                q.pop();

                // print the node
                cout << u << " ";

                // iterate through the adjacency list of the node
                for (int v : adj[u])
                {
                    // if the node is not visited
                    if (!visited[v])
                    {
                        // enqueue the node
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }

    return 0;
}
