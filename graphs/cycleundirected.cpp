#include <bits/stdc++.h>
using namespace std;

bool detect(int src , unordered_map<int,list<int>>adj,vector<bool>&vis){
    vis[src]=true;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto &&i : adj[u])
        {
            if (!vis[i])
            {
                q.push({i,u});
                vis[i]=1;
            }
            else if (i!=parent) //detection takes place here
            {
                return true;
            }
        }
    }
    return false;
}

int main(){
    unordered_map<int,list<int>>adj;
    int v,e,source;
    bool d; 
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        int u,v;    
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(v,0);
    int t = 0;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            if(detect(i,adj,vis))t=1;
        }
        
    }
    cout<<t;
}
