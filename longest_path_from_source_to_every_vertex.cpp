#include<bits/stdc++.h>
using namespace std;
// computing distance values which will be usefull for current and successor nodes
void compute(int i,vector<vector<pair<int,int>>> &adj,vector<int> &distance)
{
	for(auto u:adj[i])
	{
		if(distance[u.first]<distance[i]+u.second || distance[u.first]==INT_MAX)
			distance[u.first]=distance[i]+u.second;
	}
}
// performing topological sort to find all the vertices which can be visited from source
// vertex and finding the ordering of path to precompute their distance value.
void topological(int i,vector<vector<pair<int,int>>> &adj,stack<int> &st,vector<bool> &visited){
	visited[i]=true;
	for(auto u:adj[i]){
		if(!visited[u.first])
			topological(u.first,adj,st,visited);
	}
	st.push(i);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tcase;
	cin>>tcase;
	while(tcase--){
		int n,m;
		cin>>n>>m;
		int s;
		cin>>s;
		vector<vector<pair<int,int>>> adj(n);
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back({b,c});
		}
		stack<int> st;
		vector<bool> visited(n,false);
		topological(s,adj,st,visited);
		vector<int> distance(n,INT_MAX);
		distance[s]=0;
		while(!st.empty()){
			// if value is INT_MAX then it is not reachable from the given source vertex
			if(distance[st.top()]!=INT_MAX)
			{
			compute(st.top(),adj,distance);
			}
			st.pop();
		}
		for(int i=0;i<n;i++)
		{
			if(distance[i]==INT_MAX)
			{
				cout<<"INF"<<" ";
			}
			else
				cout<<distance[i]<<" ";
		}
		cout<<endl;
	}
}
