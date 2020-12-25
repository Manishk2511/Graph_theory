#include<bits/stdc++.h>
using namespace std;
// checking if it is possible to assign a particular colour to given node by after 
// checking it's adjacent nodes
bool possible(int i,int j,int n,vector<vector<int>> &adj,vector<int> &colours)
{
	for(int u:adj[i])
	{
		if(colours[u]==j)
			return false;
	}
	return true;
}
// for each node we will try  every colour and backtrack if it's not possible give different 
// colours to every adjacent nodes.
// so, for each node it has M choices which make it's time complexity O(M^N).
// here M is total number of colours and N is total no. of nodes.
bool solve(int i,vector<vector<int>> &adj,vector<int> &colours,int n,int M)
{
	if(i==n+1)
		return true;
	for(int j=0;j<M;j++){
		if(!possible(i,j,n,adj,colours))
			continue;
		colours[i]=j;
		if(solve(i+1,adj,colours,n,M))
			return true;
		colours[i]=-1;
	}
	return false;
}
int main()
{
	
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
	int M;
	cin>>M;
	vector<int> colours(n+1,-1);
	if(solve(0,adj,colours,n,M))
		cout<<"Possible"<<endl;
	else
		cout<<"Not possible"<<endl;

}