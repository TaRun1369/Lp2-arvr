
#include <bits/stdc++.h>
using namespace std;

class disjointSet{
    public:
  vector<int> rank,parent;
  disjointSet(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      
      for(int i= 0;i<n;i++){
          parent[i] = i;
      }
  }
  
  int findUpar(int node){
      if(node == parent[node]) return node;
      
      return parent[node] = findUpar(parent[node]);
  }
  
  void unionn(int u,int v){
      int ulp_U = findUpar(u);
      int ulp_V = findUpar(v);
      if(ulp_V == ulp_U) return;
       if(rank[ulp_V] > rank[ulp_U]){
          parent[ulp_U] = ulp_V;
         
      }
      else if(rank[ulp_V] < rank[ulp_U]){
          parent[ulp_V] = ulp_U;
      }
      else{
          parent[ulp_V] = ulp_U;
            rank[ulp_U]++;
      }
  }
};
class kruskal{
   public: 
  int spanningTree(int v,vector<vector<pair<int,int>>> &adj,vector<pair<int,int>> &mst){
      vector<pair<int,pair<int,int>>> edges;
      for(int i = 0;i<v;i++){
          for(auto it : adj[i]){
              int node = i;
              int adjnode = it.first;
              int wt = it.second;
              edges.push_back({wt,{node,adjnode}});
          }
      }
      disjointSet ds(v);
      
      sort(edges.begin(),edges.end());
      
      int mstwt = 0;
      for(auto it: edges){
          int w = it.first;
          int e1 = it.second.first;
          int e2 = it.second.second;
          
          if(ds.findUpar(e1) != ds.findUpar(e2)){
              mstwt += w;
              ds.unionn(e1,e2);
              mst.push_back({e1,e2});
          }
      }
      
      return mstwt;
      
  }  
};
int main(){
    int v,e;
    cout<<"Enter no. of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<pair<int,int>>> adj(v);
    for(int i = 0;i<e;i++){
        int src,des,wgt;
        cin>>src>>des>>wgt;
        adj[src].push_back({des,wgt});
        adj[des].push_back({src,wgt});
    }
    
    kruskal obj;
    vector<pair<int,int>> MST;
     int mstWt = obj.spanningTree(v, adj, MST);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstWt << endl;
    for(auto it : MST){
        cout<<it.first<<" - > "<<it.second<<endl;
    }
    
}