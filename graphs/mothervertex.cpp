#include <bits/stdc++.h>
using namespace std;

void dfs(int source,int v,int **adj,bool *visited,int &count){
    visited[source]=1;
    count++;    
    for (int i = 0; i < v; i++)
    {
        if (adj[source][i]==1 && (!visited[i]))
        {
            dfs(i,v,adj,visited,count); 
        }
    }
}

int main(){
    int v,e; 
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    int** adjM = new int*[v]; 

    for (int i = 0; i < v; i++)
    {
        adjM[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            adjM[i][j]=0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int u , v;
        cin>>u>>v;
        adjM[u][v]=1;
    }  
    int last_node=-1,count=0;
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            last_node=i;
            dfs(i,v,adjM,visited,count);
        }
    }
    count=0;
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    dfs(last_node,v,adjM,visited,count);
    if(count==v)cout<<last_node;
    else cout<<"no mother vertex";
    
}
