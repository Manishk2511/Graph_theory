vector <int> bfs(vector<int> g[], int N) {
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(N+1,false);
    visited[0]=true;
    q.push(0);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        ans.push_back(s);
        for(int i:g[s])
        {
            if(!visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
        
    }
    return ans;
    
}