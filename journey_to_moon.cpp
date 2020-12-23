#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int i,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &temp)
{
    visited[i]=true;
    temp.push_back(i);
    for(int u:adj[i])
    {
        if(!visited[u])
            dfs(u,adj,visited,temp);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n,false);
    vector<vector<int>> countries;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]){
            vector<int> temp;
            dfs(i,adj,visited,temp);
            countries.push_back(temp);
        }
    }
    ll total=n;
    ll ans=0;
    for(int i=0;i<countries.size()-1;i++)
    {
        for(int j=0;j<countries[i].size();j++)
        {
            ans+=(total-countries[i].size());
        }
        total-=countries[i].size();
    }
    cout<<ans<<endl;
}