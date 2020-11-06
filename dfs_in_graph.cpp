void dfs(int i,vector<int> g[],vector<bool> &visited,vector<int> &ans)
{
    ans.push_back(i);
    visited[i]=true;
    for(int u:g[i])
    {
        if(!visited[u])
        {
            dfs(u,g,visited,ans);
        }
    }
}