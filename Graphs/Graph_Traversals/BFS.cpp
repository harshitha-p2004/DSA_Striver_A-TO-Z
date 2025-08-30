#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }

int main()
{
 int n,m;
 cin>>n>>m;
 vector<int>adj[n];
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
for(int i=0;i<n;i++)
{
    for(auto it: adj[i])
    {
      if(i<it) cout<<"("<<i<<","<<it<<")"<<"\t";
    }
    
}

cout<<"\nAdjacency list: ";
for(int i=0;i<n;i++)
{
    cout<<i<<"->";
    for(auto it: adj[i])
    {
        cout<<it<<"\t";
    }
    cout<<endl;

}

cout<<"\nBFS of graph: ";
 vector<int>bfs= bfsOfGraph(n,adj);
 for(auto it:  bfs)
 {
    cout<<it<<"\t";
 }

    return 0;
}
