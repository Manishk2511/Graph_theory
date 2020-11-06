class Solution {
public:
    void dfs(int i,vector<bool> &visited,vector<vector<int>> &connections)
    {
        visited[i]=true;
        for(int u:connections[i])
        {
            if(!visited[u])
                dfs(u,visited,connections);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);

        }
         if(connections.size()<n-1)
            return -1;
        int count=0;
        vector<bool> visited(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj);
                count++;
            }
        }
        count--;
        return count;
    }
};