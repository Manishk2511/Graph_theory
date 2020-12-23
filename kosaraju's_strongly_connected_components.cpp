#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>> &adj,vector<bool> &visited)
{
    visited[i]=true;
    for(int u:adj[i])
    {
        if(!visited[u])
            dfs(u,adj,visited);
    }
}
void reverse(vector<vector<int>> &adj,vector<vector<int>> &adj1)
{
    for(int i=0;i<adj.size();i++)
    {
        for(int u:adj[i])
        {
            adj1[u].push_back(i);
        }
    }
}
void topological(int i,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &s)
{
    visited[i]=true;
    for(int u:adj[i])
    {
        if(!visited[u])
            topological(u,adj,visited,s);
    }
    s.push(i);
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
    }
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i])
            topological(i,adj,visited,s);
    }
    vector<vector<int>> adj1(n);
    reverse(adj,adj1);
    fill(visited.begin(),visited.end(),false);
    int count=0;
    while(!s.empty()){
        if(!visited[s.top()]){
            count++;
            dfs(s.top(),adj1,visited);
        }
        s.pop();
    }
    cout<<count<<endl;
}