#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int findParent(vector<int>& parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void kruskal(vector<Edge>& edges, int V, int E)
{
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv)
        {
            cout << u << " - " << v << " = " << w << endl;
            parent[pu] = pv;
        }
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

    kruskal(edges, V, E);

    return 0;
}
