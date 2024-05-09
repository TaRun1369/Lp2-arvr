#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class disjointSet{
    public:
        vector<int> rank,parent;
        disjointSet(int v){
            rank.resize(v+1,0);
            parent.resize(v+1);
            for(int i = 0;i<=v;i++){
                parent[i] = i;

            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUPar(parent[node]);

        }

        void unionn(int u,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v){
            return;
            }

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class krusk{
    public:
    int spantree(int v,vector<vector<pair<int,int>>> &adj,vector<pair<int,int>> &mstEdges){
        vector<pair<int,pair<int,int>>>edges;

        for(int i = 0;i<v;i++){
            for(auto it : adj[i]){
                int adjNode = it.first;
                int wt = it.second;
                edges.push_back({wt,{i,adjNode}});
            }
        }

        disjointSet ds(v);

        sort(edges.begin(),edges.end());

        int mstwt = 0;

        for(auto it : edges){
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;

            if(ds.findUPar(u) != ds.findUPar(v)){
                mstwt += wt;
                ds.unionn(u,v);
                mstEdges.push_back({u,v});
                
            }
        }
        return mstwt;
    }
};
int main(){
    cout<<"Enter no. of vertices and edges respectively"<<endl;
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> adj(v);
    for(int i = 0;i<e;i++){
        cout<<"enter source distination and weight of each edge"<<endl;
        int u,v,w;

        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    krusk obj;
    vector<pair<int,int>> mstEdges;
    int mstwt = obj.spantree(v,adj,mstEdges);

        cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstwt << endl;

     cout << "Edges of Minimum Spanning Tree:" << endl;
    for (auto edge : mstEdges) {
        cout << edge.first << " -- " << edge.second << endl;
    }
}