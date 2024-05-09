#include <bits/stdc++.h>
using namespace std;
void dfs(int start,vector<vector<int>>&adj,vector<int>&visited,map<int,string>&mp1){
    visited[start]=1;
    cout<<mp1[start]<<" ";
    for(auto it:adj[start]){
        if(!visited[it]){
            visited[it]=1;
            dfs(it,adj,visited,mp1);
        }
    }
}
void bfsRec(queue<int>&q,vector<int>&visited,vector<vector<int>>&adj,map<int,string>&mp1){
    if(q.empty())return;
    int node=q.front();
    q.pop();
    cout<<mp1[node]<<" ";
    for(auto it:adj[node]){
        if(!visited[it]){
            visited[it]=true;
            q.push(it);
        }
    }
    bfsRec(q,visited,adj,mp1);
}
void bfs(int start,vector<vector<int>>&adj,map<int,string>&mp1){
    vector<int>visited(adj.size(),0);
    queue<int>q;
    q.push(start);
    visited[start]=1;
    bfsRec(q,visited,adj,mp1);

}
int main(){
    map<string,int>mp;
    map<int,string> mp1;
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n);
    int mrun = 0;
    for(int i=0;i<e;i++){
        string as,ass1;
        cin>>as>>ass1;
        int u,v;
        if(mp.find(as)==mp.end()){
            mp[as] = mrun;
            mrun++;
        }
        if(mp.find(ass1) == mp.end()){
            mp[ass1] = mrun;
            mrun++;
        }
        u = mp[as];
        v = mp[ass1];
        // int u,v;
        // cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(auto it : mp){
        mp1[it.second] = it.first;
    }
    vector<int>visited(n,0);
    // bfs(0,adj,mp1);
    // dfs(0,adj,visited,mp1);
    bfs(0,adj,mp1);

}