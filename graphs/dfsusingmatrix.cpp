#include <bits/stdc++.h>
using namespace std;

void dfs(int source,int v,int **adj,bool *visited){
    visited[source]=1;
    cout<<source<<" ";      
    for (int i = 0; i < v; i++)
    {
        if (adj[source][i]==1 && (!visited[i]))
        {
            dfs(i,v,adj,visited);  //using recursion
        }
    }
}

int main(){
    int v,e; // v is no. of vertices & n is no. of edges
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    int** adjM = new int*[v]; //creating 2d matrix dynamically

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
        adjM[v][u]=1;   //for directed graph skip this line 
    }  

    /*for (int i = 0; i < v; i++)      //printing the adj matrix
    {
        for (int j = 0; j < v; j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }*/
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    
    dfs(1,v,adjM,visited);
}
