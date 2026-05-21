#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void prims(vector<vector<int>>& graph, int V)
{
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX;
        int u;

        for (int i = 0; i < V; i++)
        {
            if (!mst[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        mst[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " = " << graph[i][parent[i]] << endl;
    }
}

int main()
{
    int V;

    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    prims(graph, V);

    return 0;
}
