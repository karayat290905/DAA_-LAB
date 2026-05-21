#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int v, const vector<vector<int>>& adj){
    vector<int> color(v,-1);
    queue<int> q;

    for (int j = 0;j < v; j++){
        if (color[j]==-1){ 
            color[j] =0; 
            q.push(j);

            while (!q.empty()) {
                int node =q.front();
                q.pop();

                for(int i:adj[node]){
                    if(color[i] == -1){
                        color[i] = 1-color[node];
                        q.push(i);
                    } else if(color[i] == color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int v, e;
    cout<< "Enter number of vertices and edges: ";
    cin>> v >> e;

    vector<vector<int>>adj(v);

    cout<<"Enter edges (u v):"<<endl;
    for (int i = 0; i < e; i++) {
        int u, v2;
        cin>>u>>v2;
        adj[u].push_back(v2);
        adj[v2].push_back(u);
    }

    if(isBipartite(v,adj))
        cout<<"The graph is bipartite."<<endl;
    else
        cout<<"The graph is not bipartite."<<endl;

    return 0;
}
