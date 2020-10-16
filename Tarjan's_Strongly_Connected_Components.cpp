#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int> &disc,vector<int> &low,vector<bool> &inStack,stack<int> &s,vector<vector<int>> &adj)
{
    static int time=0;
    disc[i]=time;
    low[i]=time;
    time++;
    s.push(i);
    inStack[i]=true;
    for(int u:adj[i])
    {
        if(disc[u]==-1)
        {
            dfs(u,disc,low,inStack,s,adj);
            low[i]=min(low[u],low[i]);
        }
        else if(inStack[u]==true)
        {
            low[i]=min(low[i],disc[u]);
        }
    }
    if(disc[i]==low[i])
    {
        while(s.top()!=i)
        {
            cout<<s.top()<<" ";
            inStack[s.top()]=false;
            s.pop();
        }
        cout<<s.top()<<endl;
        inStack[s.top()]=false;
        s.pop();
    }

}
void tarjan(vector<vector<int>> &adj)
{
    vector<int> disc(adj.size(),-1);
    vector<int> low(adj.size());
    vector<bool> inStack(adj.size(),false);
    stack<int> s;
    for(int i=0;i<adj.size();i++)
    {   
        if(disc[i]==-1)
            dfs(0,disc,low,inStack,s,adj);
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
    tarjan(adj);
}