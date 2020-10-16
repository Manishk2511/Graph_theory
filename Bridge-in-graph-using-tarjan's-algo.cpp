#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<pair<int,int>> &bridges)
{
    static int time=0;
    disc[i]=low[i]=time;
    time++;
    for(int u:adj[i])
    {
        if(disc[u]==-1)
        {   
            parent[u]=i;
            dfs(u,adj,disc,low,parent,bridges);
            low[i]=min(low[u],low[i]);

            // when there's no back edge from any subgraph of current node
            // then low value of child will be greater then discovery value of 
            // parent. So, this makes the edge a bridge.

            if(low[u]>disc[i])
            {
                bridges.push_back({i,u});
            }
        }
        else if(parent[i]!=u){
            // if there's any back edge from the node then we will update the low value 
            // as we can reach to some node directly. Every back edge is not a bridge as it
            // is in the same component and counted as extra edge so there's no effect in 
            // deleting it.
            low[i]=min(low[i],disc[u]);
        }
    }
}
void find_bridges(vector<vector<int>> &adj,int n)
{
    vector<pair<int,int>> bridges;
    vector<int> disc(n,-1),low(n,-1),parent(n,-1);
    cout<<"Bridges are : "<<endl;
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
            dfs(0,adj,disc,low,parent,bridges);
    }
    for(auto i:bridges)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    find_bridges(adj,n);

}


