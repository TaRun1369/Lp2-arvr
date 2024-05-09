#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>


using namespace std;

void dfs(vector<vector<int>> &adj,vector<int> &visited,int start,map<int,string> &mp){
    if(visited[start]) return;
    visited[start] = 1;
    cout<<mp[start]<<" ";
    for(auto it : adj[start]){
        if(!visited[it]){
            dfs(adj,visited,it,mp);
            
        }
    }
}
void bfsrec(vector<vector<int>> &adj,vector<int> &visited,queue<int> &q,map<int,string> &mp){
    if(q.empty()) return;
    int f = q.front();
    q.pop();
    cout<<mp[f]<<" ";
    for(auto it : adj[f]){
        if(!visited[it]){
            q.push(it);
            visited[it] = 1;
        }

    }
    bfsrec(adj,visited,q,mp);

}
void bfs(vector<vector<int>> &adj,map<int,string> &mp){
    vector<int> visited(adj.size(),0);
    int start;
    cout<<"where to stART"<<endl;
    cin>>start;
    queue<int> q;
    q.push(start);
    visited[start] =1;
    bfsrec(adj,visited,q,mp);
}
int main(){
    map<int,string> mp1;
    map<string ,int> mp;
    int v,e;
    cout<<"Enter no. of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<int>> adj(v);
    int c = 0;
    for(int i = 0;i<e;i++){
        string one , two;
        cout<<"ENter starting node and ending node"<<endl;
        cin>>one>>two;
        
        int u,v;
        if(mp.find(one) == mp.end()){
         u = c;
        mp[one] = u;
        c++;
        
        }
        if(mp.find(two) == mp.end()){
              v = c;
             mp[two] = c;
             c++;
             
        }
       
        
        // cin>>u>>v;


        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto it : mp1){
        mp[it.second] = it.first;
    }
    int start;
    cout<<"where to start"<<endl;
    cin>>start;
    vector<int> visited(v,0);
    cout<<"DFS is "<<endl;
    dfs(adj,visited,start,mp1);
    cout<<"bfs is "<<endl;
    bfs(adj,mp1);
    
}