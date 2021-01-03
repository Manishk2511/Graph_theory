#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	vector<int> degree(n);
	vector<pair<int,int>> pairs(n);
	vector<vector<int>> adj(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	for(int i=0;i<n;i++)
	{
		pairs[i].first=degree[i];
		pairs[i].second=i;
	}
	sort(pairs.rbegin(),pairs.rend());
	vector<bool> visited(n,false);
	cout<<"Minimum vertex cover is : "<<endl;
	for(auto i:pairs)
	{
		if(visited[i.second])
			continue;
		cout<<i.second<<" ";
		for(int u:adj[i.second])
		{
			if(!visited[u]){
				visited[u]=true;
			}

		}
	}	
	cout<<endl;

}