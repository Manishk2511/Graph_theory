#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// floyd warshall algo calculates shortest paths using direct edges and
// paths using indirect edges by putting other nodes in between direct edges.
// it has O(n^3) time complexity where n is the number of nodes.
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll tcase;
	cin>>tcase;
	while(tcase--)
	{
		ll n;
		cin>>n;
		vector<vector<ll>> adj(n,vector<ll>(n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>adj[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			// adding intermediate nodes
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if(adj[j][k]>(adj[j][i]+adj[i][k]))
					{
						adj[j][k]=adj[j][i]+adj[i][k];
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}