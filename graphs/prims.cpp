#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,list<pair<int,int>>>adj;
    int v,e; 
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    vector<int>key(v,INT_MAX);
    vector<bool>mst(v,0);
    vector<int>parent(v,-1);
    key[0]=0;
    for (int i = 0; i < v; i++)
    {
        int mini = INT_MAX;
        int in=-1;
        for (int j = 0; j < v; j++)
        {
            if(!mst[j] && key[j]<mini){
                mini = key[j];
                in = j;
            }
        }
        mst[in]=1;
        for(auto it : adj[in]){
            int node = it.first;
            int weight = it.second;
            if(!mst[node] && weight<key[node]){
                parent[node]=in;
                key[node]=weight;
            }
        }
           
    }
    vector<pair<pair<int,int>,int>>ans;
    int cost = 0;
    for (int i = 1; i < v; i++)
    {
        ans.push_back({{parent[i],i},key[i]});
        cost+=key[i];
    }
    for (int i = 0; i < v-1; i++)
    {
        cout<<ans[i].first.first<<"---"<<ans[i].first.second<<"   "<<ans[i].second<<endl;
    }
}
