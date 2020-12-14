#include<bits/stdc++.h>
using namespace std;
// this code will return 1 if there is a negative weight edge cycle in a graph using 
// bellman ford algo. If we are continuously getting value of nodes minimum in each iteration
// then there must be a negative weight cycle in the graph
// so, if we iterate through every nodes for n+1 (n is total number of nodes) times 
// and still getting new minimum value then we can say that there is a negative cycle weight 
// cycle in the graph.
class edge{
public:
	int a,b,c;
};
int bellman_ford(vector<edge> &v,int n){
	vector<int> distance(n,INT_MAX);
	distance[0]=0;
	int count=0;
	//iterating through every node for n+1 times.
	while(count<=n)
	{
		bool flag=false;
		for(auto e:v)
		{
			if(distance[e.b]>distance[e.a]+e.c)
			{
				distance[e.b]=distance[e.a]+e.c;
				flag=true;
			}
		}
		// if values are not changing then we can stop here.
		if(!flag)
			break;
		if(count==n)
		{
			// if graph contains negative weight cycle.
			return 1;
		}
		count++;
	}
	return 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tcase;
	cin>>tcase;
	while(tcase--)
	{
	int n,e;
	cin>>n>>e;
	// taking edge list vector because we have to iterate through every node 
	// in the graph.
	vector<edge> v(e);
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[i].a=a;
		v[i].b=b;
		v[i].c=c;
	}
	cout<<bellman_ford(v,n)<<endl;
	}
}