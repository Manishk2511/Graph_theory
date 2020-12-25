#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,int target,int sum,vector<vector<pair<int,int>>> &adj,vector<bool> &visited)
{
	if(sum>=target){
		cout<<sum<<endl;
		return target;
	}
	visited[i]=true;
	// performing backtracking on graph and finding all possible paths 
	for(auto u:adj[i])
	{
		if(!visited[u.first])
		{
			if(dfs(u.first,target,sum+u.second,adj,visited))
				return true;
		}
	}
	visited[i]=false;
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m,source,target;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	// checking existence of a path with total distance of path greater than given target
	cin>>source>>target;
	vector<bool> visited(n+1,false);
	if(dfs(source,target,0,adj,visited))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

}