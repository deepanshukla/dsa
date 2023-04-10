#include <bits/stdc++.h>
using namespace std;

void bfs(int source,int v,int **adj,bool *visited){
    queue<int>q;
    q.push(source);
    visited[source]=1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for (int i = 0; i < v; i++)
        {    
            if ( adj[i][u]==1 && (!visited[i]))
            {   
                visited[i]=true;
                q.push(i);
            }
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
        adjM[i] = new int[v]; //initiallising the mat
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
        adjM[v][u]=1; //for directed graph skip this line 
    }  

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    
    bfs(0,v,adjM,visited);
}
