#include<bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &adj,int s,int t,vector<int> &parent,vector<vector<int>> &capacity)
{

	fill(parent.begin(),parent.end(),-1);
	parent[s]=-2;
	queue<pair<int,int>> q;
	q.push({s,INT_MAX});
	while(!q.empty())
	{
		int flow=q.front().second;
		int prev=q.front().first;
		q.pop();
		for(int curr:adj[prev])
		{
			// checking if node is not visited and the edge must have positive value
			if(parent[curr]==-1 && capacity[prev][curr]!=0)
			{
				// taking min flow because the maximum amount of flow it can pass through path
				// is the minimum capacity of any particular node in the path.
				flow=min(flow,capacity[prev][curr]);
				q.push({curr,flow});
			
				parent[curr]=prev;
				if(curr==t)
				{
					// if we reach sink then the path has found and it will return the flow
					return flow;
				}
			}
		}
	}

	return 0;
}
Edmonds_karp(vector<vector<int>> &adj,int s,int t,vector<vector<int>> &capacity,int n)
{
	// using parent array to mark visited node as well as while updating flow.
	vector<int> parent(n+1);
	int maxflow=0;
	int flow;
	// if bfs return 0 then it means there are no remaining positive value path from source to sink.
	while(flow=bfs(adj,s,t,parent,capacity))
	{
		int current=t;
		// updating the flow of forward and reverse flow edge
		while(current!=s)
		{
			int prev=parent[current];
			capacity[prev][current]-=flow;
			capacity[current][prev]+=flow;
			current=prev;
		}
		maxflow+=flow;
	}
	return maxflow;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;
	int s,t;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	vector<vector<int>> capacity(n+1,vector<int>(n+1));
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		// as there are two types of edges i.e, forward edge and reverse edge.
		// when value of forward edge decreases reverse edge increases and vice versa.
		capacity[a][b]=c;
		capacity[b][a]=0;
	}
	cin>>s>>t;
	cout<<Edmonds_karp(adj,s,t,capacity,n)<<endl;
}

// used to find maximum flow in the graph.
// maximum flow means the maximum amount of flow which can be given from the source node 
// to then sink node. here source node has no incoming edge and sink node has no outgoing edge.