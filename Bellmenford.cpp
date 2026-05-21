#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

void bellmanFord(vector<Edge>& edges, int V, int E, int source)
{
    vector<int> dist(V, INT_MAX);

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative Weight Cycle Found";
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from " << source << " to " << i << " = " << dist[i] << endl;
    }
}

int main()
{
    int V, E;

    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    bellmanFord(edges, V, E, source);

    return 0;
}
