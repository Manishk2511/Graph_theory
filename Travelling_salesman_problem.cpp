#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static bool compare(vector<int> &a,vector<int> &b)
{
	return a.size()<b.size();
}
void combination(set<vector<int>> &s,vector<int> v,int index,int n){
	if(index==n)
	{
		s.insert(v);
		return;
	}
	for(int i=index;i<n;i++)
	{
		v.push_back(i);	
		s.insert(v);
		combination(s,v,i+1,n);
		v.pop_back();
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tcase;
	cin>>tcase;
	while(tcase--)
	{
		int n;
		cin>>n;
		vector<vector<int>> v(n,vector<int>(n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>v[i][j];
			}
		}
		map<pair<int,int>,int> m;
		map<pair<int,int>,int> index;
		vector<vector<int>> sets;
		set<vector<int>> st;
		vector<int> temp;
		combination(st,temp,1,n);
		for(auto i:st)
		{
			// for(int j=0;j<i.size();j++)
			// {
			// 	cout<<i[j]<<" ";
			// }
			// cout<<endl;
			sets.push_back(i);
		}
		for(int i=1;i<n;i++)
		{
			m[{i,1}]=v[0][i];
		}
		sort(sets.begin(),sets.end(),compare);
		// for(int i=0;i<sets.size();i++)
		// {
		// 	for(int j=0;j<sets[i].size();j++)
		// 	{
		// 		cout<<sets[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int i=0;i<sets.size()-1;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(find(sets[i].begin(),sets[i].end(),j)==sets[i].end())
				{
					if(sets[i].size()==1)
					{
						ll value=v[sets[i][0]][j]+v[0][sets[i][0]];
						if(m.count({j+sets[i][0],2}))
						{
							if(value<m[{j+sets[i][0],2}]){
								m[{j+sets[i][0],2}]=value;
								index[{j+sets[i][0],2}]=j;
							}
						}
						else{
							m[{j+sets[i][0],2}]=value;
							index[{j+sets[i][0],2}]=j;
						}	
					}
					else{	
						int sum=0;
						for(int k=0;k<sets[i].size();k++)
						{
							sum+=sets[i][k];
						}
						ll ans=m[{sum,sets[i].size()}];
						ans+=v[index[{sum,sets[i].size()}]][j];
						if(m.count({sum+j,sets[i].size()+1}))
						{
							if(ans<m[{j+sum,sets[i].size()+1}]){
								m[{j+sum,sets[i].size()+1}]=ans;
								index[{j+sum,sets[i].size()+1}]=j;
							}
						}
						else{
							index[{j+sum,sets[i].size()+1}]=j;
							m[{j+sum,sets[i].size()+1}]=ans;
						}
					}
				}
			}
		}
		int i;
		// for(auto i:m)
		// {
		// 	cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
		// }
		int s=sets.size()-1;
		int sum=0;
		for(int k=0;k<sets[s].size();k++)
		{
			sum+=sets[s][k];
		}
		ll ans=m[{sum,sets[s].size()}];
		ans+=v[index[{sum,sets[s].size()}]][0];
		cout<<ans<<endl;
	}
}