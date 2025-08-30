#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main()
{

int n,m;
cin>>n>>m;
int adj[n+1][n+1]={0};
vector<pair<int,int>>edges;
for(int i=0;i<m;i++)
{
  int u,v;
  cin>>u>>v;
  adj[u][v]=1;
  adj[v][u]=1;
  edges.push_back({u,v});

}

cout<<"\nNo of Vertices: "<<n;
cout<<"\nNo of Edges: "<<m;
cout<<"\nEges Connections: ";

for(int i=0;i<edges.size();i++)
{
    cout<<"("<<edges[i].first<<","<<edges[i].second<<")";
    cout<<"\t";
}

cout<<"\n\nAdjacency Matrix:";
for(int i=1;i<=n;i++)
{
    cout<<"\n";
    for(int j=1;j<=n;j++)
    {
        cout<<adj[i][j];
    }
    
}

    return 0;
}
