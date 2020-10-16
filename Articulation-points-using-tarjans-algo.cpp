// articulation point is used to identify single point of failure in the network.
//using tarjans scc algo as base

include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<bool> &articulation){
    static int time=0;
    int c=0;
    disc[i]=low[i]=time;
    time++;
    for(int u:adj[i])
    {
        if(disc[u]==-1)
        {
            c++;
            parent[u]=i;
            dfs(u,adj,disc,low,parent,articulation);
            low[i]=min(low[i],low[u]);
            // case 1: when node is the root of the tree
            //then if it has >=2 sub-graphs which are not connected then it's
            // an articulation point.
            if(parent[u]==-1 && c>1)
            {
                articulation[i]=true;
            }
            // case 2 : when a node is not root of the tree and if it doesn't have 
            // any back edge then it will be an articulation point.
            if(parent[u]!=-1 && low[u]>=disc[i])
            {
                articulation[i]=true;
            }
        }
        else if(parent[u]=!i)
        {
            // if there's any back edge from current node then we update low.
            low[i]=min(low[i],disc[u]);
        }
    }
    
}
void articulation_points(int n,vector<vector<int>> &adj)
{
    // using parent for verification of back edge and ignoring parent as back edge.
    vector<int> disc(n,-1),low(n,-1),parent(n,-1);
    vector<bool> articulation(n,false);
    dfs(0,adj,disc,low,parent,articulation);
    for(int i=0;i<n;i++)
    {
        if(articulation[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    articulation_points(n,adj);

}