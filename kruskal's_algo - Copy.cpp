#include<bits/stdc++.h>
using namespace std;
static bool compare(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
{
	return a.second.second<b.second.second;
}
int find(int x,vector<int> &parent)
{
	if(parent[x]==x)
		return x;
	return (parent[x]=find(parent[x],parent));
}
void Union(int a,int b,vector<int> &parent,vector<int> &rank)
{
	if(rank[a]<rank[b])
	{
		parent[a]=b;
	}
	else if(rank[b]<rank[a])
	{
		parent[b]=a;
	}
	else{
		parent[a]=b;
		rank[a]+=1;
	}

}
int kruskal(vector<pair<int,pair<int,int>>> &adj,vector<int> &parent,vector<int> &rank,int n){
	int ans=0;
	int count=0;
	int i=0;
	while(i<adj.size() && count<n-1)
	{
		int a=adj[i].first;
		int b=adj[i].second.first;
		if(find(a,parent)!=find(b,parent)){
			Union(a,b,parent,rank);
			ans+=adj[i].second.second;
			count++;
		}
		i++;
	}
	return ans;
}
int main()
{
  #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  #endif
	
  int n,m;
  cin>>n>>m;
  vector<int> rank(n+1,0);
	vector<int> parent(n+1);
  vector<pair<int,pair<int,int>>> adj;
  for(int i=0;i<m;i++)
  {
      int a,b,c;
      cin>>a>>b>>c;
      adj.push_back({a,{b,c}});
  }
  for(int i=0;i<=n;i++)
  {
  	parent[i]=i;
  }
  sort(adj.begin(),adj.end(),compare);
  cout<<kruskal(adj,parent,rank,n)<<endl;

}
