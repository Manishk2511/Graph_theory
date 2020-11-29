#include<bits/stdc++.h>
using namespace std;
vector<int> st,v;
int n;
void update(int pos,int value,int l=0,int r=n-1,int index=0)
{
	if(pos<l || pos>r) return;
	if(l==r)
	{
		v[pos]=value;
		st[index]=value;
		return;
	}
	int mid=(l+r)/2;
	update(pos,value,l,mid,2*index+1);
	update(pos,value,mid+1,r,2*index+2);
	st[index]=min(st[2*index+1],st[2*index+2]);
}
int build(int index=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		st[index]=v[l];
		return v[l];
	}
	int mid=(l+r)/2;
	st[index]=min(build(2*index+1,l,mid),build(2*index+2,mid+1,r));
	return st[index];
}
int querry(int l,int r,int L=0,int R=n-1,int index=0){
	if(L>r || R<l)
		return INT_MAX;

	if(L>=l && R<=r)
		return st[index];

	int mid=(L+R)/2;
	return min(querry(l,r,L,mid,2*index+1),querry(l,r,mid+1,R,2*index+2));
}	






int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	int q;
	
	v.resize(n);
	st.resize(n*4);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	build();
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		cout<<querry(a,b)<<endl;
	}
	int pos,value;
	cin>>pos>>value;
	pos--;
	update(pos,value);
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		cout<<querry(a,b)<<endl;
	}
}