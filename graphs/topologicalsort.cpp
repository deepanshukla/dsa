#include <bits/stdc++.h>
using namespace std;

void topsort(int node,vector<bool>&visited,stack<int>&s,vector<int> adj[]){
        visited[node]=true;
        for (auto &n : adj[node])
        {
            if (!visited[n])
            {
                topsort(n,visited,s,adj);
            }
        }
        s.push(node);
    }
vector<int> topoSort(int v, vector<int> adj[]) 
{
    vector<bool>visited(v,0);
    stack<int>s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topsort(i,visited,s,adj);
        }
        
    }
    vector<int>ans;
    while (!s.empty())  
    {
        int x = s.top();
        s.pop();
        ans.push_back(x);
        
    }
    return ans;
}

int main(){
    int v,e;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    vector<int>adj[v];
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>res;
    res = topoSort(v,adj);
    for (auto &&i : res)
    {
        cout<<i<<" "; 
    }
}
