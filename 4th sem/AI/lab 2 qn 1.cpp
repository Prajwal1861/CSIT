#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm> // For sort()

using namespace std;

// Function to perform Depth First Search (DFS)
void dfs (int start, const vector<vector<int>>& adj, vector<bool>& visited)
 {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;

            // Traverse neighbors in reverse order for left-to-right consistency
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}

// Function to perform Breadth First Search (BFS)
void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n = 12; // Number of nodes in the graph
    vector<vector<int>> adj(n + 1); // Adjacency list representation (1-indexed)

    // Adding directed edges to the graph
    adj[1] = {2, 7, 8};
    adj[2] = {3, 6};
    adj[3] = {4, 5};
    adj[8] = {9, 12};
    adj[9] = {10, 11};

    // Optional: Sort adjacency lists to ensure consistent traversal order
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS Traversal
    cout << "DFS Traversal: ";
    vector<bool> visited_dfs(n + 1, false);
    dfs(1, adj, visited_dfs);
    cout << endl;

    // BFS Traversal
    cout << "BFS Traversal: ";
    vector<bool> visited_bfs(n + 1, false);
    bfs(1, adj, visited_bfs);
    cout << endl;

    return 0;
}

