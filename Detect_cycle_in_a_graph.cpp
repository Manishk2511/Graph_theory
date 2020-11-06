bool dfs(int i,vector<int> &type,vector<int> adj[])
{
    type[i]=1;
    for(int u:adj[i])
    {
       if(type[u]==0 && dfs(u,type,adj))
       {
           return true;
       }
       else if(type[u]==1)
       {
           return true;
       }
    }
    type[i]=2;
    return false;

}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> type(V+1,0);
    for(int i=0;i<V;i++)
    {
        if(type[i]==0)
        {
            if(dfs(i,type,adj))
            {
                return true;
            }
        }
    }
    return false;
    // Your code here
}