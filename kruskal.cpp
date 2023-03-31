#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int u,v,w;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<Edge>> adj(n);
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({u,v,w});
        adj[v].push_back({v,u,w});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<n;i++){
        for(auto &e:adj[i]){
            pq.push({e.w,{e.u,e.v}});
        }
    }
    set<int> taken;
    vector<int> parent(m,-1);
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int u=p.second.first;
        int v=p.second.second;
        if(taken.find(u)!=taken.end() && taken.find(v)!=taken.end()){
            continue;
        }
        taken.insert(u);
        taken.insert(v);
        parent[v]=u;
    }
}