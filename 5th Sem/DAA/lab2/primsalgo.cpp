#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, iterations = 0;
    cout << "Enter number of vertices: ";
    cin >> n;

    int G[n][n];
    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> G[i][j];

    int key[n], parent[n];
    bool mst[n];

    for(int i=0;i<n;i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count<n-1; count++)
    {
        int u = -1, min = INT_MAX;

        for(int i=0;i<n;i++)
        {
            iterations++;
            if(!mst[i] && key[i] < min)
                min = key[i], u = i;
        }

        mst[u] = true;

        for(int v=0; v<n; v++)
        {
            if(G[u][v] && !mst[v] && G[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = G[u][v];
            }
        }
    }

    int cost = 0;
    for(int i=1;i<n;i++)
        cost += G[i][parent[i]];

    cout << "Minimum Cost: " << cost;
    cout << "\nIterations: " << iterations;
    return 0;
}

