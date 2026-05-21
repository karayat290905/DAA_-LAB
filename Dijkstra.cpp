#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v,vector<vector<int>>&adj,int src){
    vector<int>dist(v,INT_MAX);
    vector<bool>vis(v,false);

    dist[src]=0;

    for(int i =0;i<v;i++){
        int u = -1;
        for(int j=0;j<v;j++){
            if(!vis[j]&&(u==-1||dist[j]<dist[u]))u=j;
        }

        vis[u]=true;

        for(int j=0;j<v;j++){
            if(adj[u][j]!= 0 && !vis[j]){
                dist[j] = min(dist[j],dist[u]+adj[u][j]);
            }
        }
    }
    return dist;
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<vector<int>>adj(v,vector<int>(v,0));

    for(int i=0;i<e;i++){
        int u,v2,w;
        cin>>u>>v2>>w;
        adj[u][v2] = w;
        adj[v2][u] = w;
    }

    int src;
    cin>>src;

    vector<int>dist = dijkstra(v,adj,src);

    for(int i=0;i<v;i++){
        if(dist[i]==INT_MAX)cout<<"INF ";
        else cout<<dist[i]<<" ";
    }

    return 0;
}
