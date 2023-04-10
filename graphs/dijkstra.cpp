#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,list<pair<int,int>>>adj;
    int v,e,source; 
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    cout<<"enter the source"<<endl;
    cin>>source;
    for (int i = 0; i < e; i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v,INT_MAX);
    dist[source]= 0;
    pq.push({0,source});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int topnode = pq.top().second;
        pq.pop();
        for (auto &&it : adj[topnode])
        {
            if (distance + it.second < dist[it.first])
            {
                dist[it.first]=distance + it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    for (auto &&i : dist)
    {
        cout<<i<<" ";
    }
}
