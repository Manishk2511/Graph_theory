#include<bits/stdc++.h>
using namespace std;
void pre(vector<vector<int>> &parent,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<log2(n);j++)
        {
            if(parent[i][j-1]!=-1)
            {
                parent[i][j]=parent[parent[i][j/2]][j/2];
            }
        }
    }
}
void dfs(int i,int ancestor,vector<vector<int>> &parent,vector<vector<int>> &adj,vector<int> &depth)
{
    parent[i][0]=ancestor;
    for(int u:adj[i])
    {
        depth[u]=depth[i]+1;
        dfs(u,i,parent,adj,depth);
    }
}
int lca(int a,int b,vector<int> &depth,vector<vector<int>> &parent)
{
    if(depth[a]>depth[b]) swap(a,b);
    int diff=depth[b]-depth[a];
    while(diff>0)
    {
        int j=log2(diff);
        b=parent[b][j];
        diff-=1<<j;
    }
    if (a==b) return a;
    for(int i=log2(parent.size()-1);i>=0;i--)
    {
        if(parent[a][i]!=-1 && (parent[a][i]!=parent[b][i]))
        {
            a=parent[a][i],b=parent[b][i];
        }
    }
    return parent[a][0];
}
int get_distance(int a,int b,int c,vector<int> &depth)
{
    return depth[a]+depth[b]-2*depth[c];
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int node1,node2;
    cin>>node1>>node2;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> depth(n+1);  
    depth[1]=0;
    vector<vector<int>> parent(n+1,vector<int>(log2(n),-1));
    dfs(1,-1,parent,adj,depth);
    int LCA=lca(node1,node2,depth,parent);
    cout<<get_distance(node1,node2,LCA,depth)<<endl;

}