#include<iostream>
#include<vector>
using namespace std;

int main()
{
 int n,m;
 cin>>n>>m;
 vector<int>adj[n+1];
 for(int i=0;i<m;i++)
 {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
 }

cout<<"\nNo of Vertices: "<<n;
cout<<"\nNo of Edges: "<<m;
cout<<"\nEdges Connections:\n";
for(int i=1;i<=n;i++)
{
    for(auto it: adj[i])
    {
      if(i<it) cout<<"("<<i<<","<<it<<")"<<"\t";
    }
    
}

cout<<"\nAdjacency list: ";
for(int i=1;i<=n;i++)
{
    cout<<i<<"->";
    for(auto it: adj[i])
    {
        cout<<it<<"\t";
    }
    cout<<endl;

}

    return 0;
}
