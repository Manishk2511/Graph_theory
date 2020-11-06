bool dfs(int i,vector<bool> &visited,vector<int> g[],int parent)
{
    visited[i]=true;
    for(int u:g[i])
    {
        if(!visited[u])
        {
            if(dfs(u,visited,g,i))
                     return true;
        }
        else if(visited[u] && u!=parent)
        {
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,visited,g,-1))
                 return true;
        }
    }
   // Your code here
   return false;
}