#include<bits/stdc++.h>
using namespace std;
void dfsPrint(int i,vector<vector<int>> &adj,vector<bool> &visited)
{
	visited[i]=true;
	cout<<i<<" ";
	for(int u:adj[i])
	{
		if(!visited[u])
		{
			dfsPrint(u,adj,visited);
		}
	}
}
void printPath(vector<vector<int>> &adj,int n,vector<int> &degree,bool flag){
	vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(!flag){
			if(degree[i]==1){
				dfsPrint(i,adj,visited);
				break;
			}
		}
		else{
			if(degree[i]>0)
			{
				dfsPrint(i,adj,visited);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			cout<<i<<" ";
		}
	}
}
void dfs(int i,vector<vector<int>> &adj,vector<bool> &visited)
{
	visited[i]=true;
	for(int u:adj[i])
	{
		if(!visited[u])
		{
			dfs(u,adj,visited);
		}
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
	vector<vector<int>> adj(n+1);
	vector<int> degree(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		degree[a]++;
		degree[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(degree[i]>0)
		{
			dfs(i,adj,visited);
			break;
		}
	}
	int odd=0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i] && degree[i]>0)
		{
			cout<<"Non eulerian graph"<<endl;
			return 0;
		}
		else{
			if(degree[i]&1){
				odd++;
			}
		}
	}
	bool flag=false;
	if(odd==0)
		flag=true;
	if(odd==0 || odd==2)
	{
		printPath(adj,n,degree,flag);
		cout<<endl;
	}
	else{
		cout<<"Not Possible"<<endl;
	}
}