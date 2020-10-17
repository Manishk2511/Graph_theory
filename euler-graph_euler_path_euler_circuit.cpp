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
bool connected(vector<vector<int>> &adj,int n){
    vector<bool> visited(n,false);
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>0)
        {
            dfs(i,adj,visited);
            break;
        }
    }
    // if there are nodes outside a component and those nodes have edges then 
    // this graph can't be called euler graph.
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(adj[i].size()>0)
                return false;
        }
    }
    return true;

}
int euler_graph(vector<vector<int>> &adj,int n)
{
    // counting the number of nodes which have odd degree.
    // if more than two nodes have odd degree then eulaer graph is not possible.
    int odd=0;
    // checking if all the edges belong to a single component and no other edges are 
    // present outside a component.
    // if it's there then it's not an euler graph
    if(!connected(adj,n))
        return 0;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()&1)
            odd++;
    }
    // if we have two nodes with odd degree then they must be starting and ending
    // node of eauler path which is also called semi eular graph.
    if(odd>2)
        return 0;
    // if all the edges have even degree then it is an eular circuit that starts 
    // and ends at same node and it is also called euler graph.
    if(odd==0)
        return 1;
    return 2;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=euler_graph(adj,n);
    if(ans==0)
    {
        cout<<"Non-Euler graph"<<endl;
    }
    else if(ans==1)
    {
        cout<<"Euler graph"<<endl;
    }
    else
    {
        cout<<"Semi-Euler graph"<<endl;
    }
}


// semi euler graph is a graph which hase euler path
// euler graph is graph which has euler circuit
// euler path is a path which goes through each edge of graph exactly once.
// euler circuit is a euler path which starts and end at same node.