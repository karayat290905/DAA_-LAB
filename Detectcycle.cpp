#include<bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>>& adj, vector<int>& vis){
    queue<pair<int,int>> q;
    q.push({src,-1});
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,node});
            }
            else if(it != parent){
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj, int v){
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(bfs(i,adj,vis)) return true;
        }
    }
    return false;
}

int main(){
    int v,e;
    cout<<"Enter the number of vertices and edges:";
    cin>>v>>e;

    vector<vector<int>>adj(v);
    
    cout<<"Enter edges (u v):"<<endl;
    for (int i = 0; i < e; i++) {
        int u, v2;
        cin>>u>>v2;
        adj[u].push_back(v2);
        adj[v2].push_back(u);
    }

    if(detectCycle(adj,v)) cout<<"Cycle detected\n";
    else cout<<"No cycle\n";

    return 0;
}
