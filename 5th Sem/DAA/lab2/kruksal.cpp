#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100], iterations = 0;

int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    Edge A[e];
    cout << "Enter u v w:\n";
    for(int i=0;i<e;i++)
        cin >> A[i].u >> A[i].v >> A[i].w;

    sort(A, A+e, cmp);

    for(int i=0;i<n;i++)
        parent[i] = i;

    int cost = 0;

    for(int i=0;i<e;i++)
    {
        iterations++;
        int x = find(A[i].u);
        int y = find(A[i].v);

        if(x != y)
        {
            parent[x] = y;
            cost += A[i].w;
        }
    }

    cout << "Minimum Cost: " << cost;
    cout << "\nIterations: " << iterations;
    return 0;
}

