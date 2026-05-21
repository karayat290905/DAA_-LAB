#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>&adj,vector<bool>&vis){
    vis[node] = true;
    cout<<node+1<<"  ";
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
            DFS(neighbour,adj,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    vector<bool>vis(n,false);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int source;
    cin>>source;
    DFS(source,adj,vis);
    return 0;
}
