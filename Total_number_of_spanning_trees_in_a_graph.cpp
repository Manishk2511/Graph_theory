#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// for removing row and column and creating new vector for computations
void create(vector<vector<int>> &temp,vector<vector<int>> matrix,int k,int l,int N)
{
	int m=0,n=0;
	for(int i=0;i<N;i++)
	{
		m=0;
		if(i!=k){
			for(int j=0;j<N;j++)
			{
				if(j!=l){
					temp[n][m]=matrix[i][j];
					m++;
				}
			}
			n++;
		}
	}
}
// calculating co-factor by selecting any particular element in matrix as all give same ans.
int cofactor(vector<vector<int>> matrix,int n){
	if(n==1)
		return matrix[0][0];
	// for computations of sign for multiplication as it keeps changing as column changes.
	int sign=1; 
	ll d=0;
	vector<vector<int>> temp(n,vector<int>(n,0));
	// calculating values for each column of first row of matrix.
	for(int i=0;i<n;i++)
	{
		// create function for removing one row and one column in which selected 
		//element is present.
		create(temp,matrix,0,i,n);
		d+=(sign*matrix[0][i]*(cofactor(temp,n-1)));
		sign=-sign;
	}
	return d;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	vector<int> degree(n+1,0);
	vector<vector<int>> matrix(n,vector<int>(n,0));
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		// if elements are 1-index based.
		matrix[a][b]=-1;
		matrix[b][a]=-1;
		degree[a]++;
		degree[b]++;
		// degree is needed to be computed as it is required for diagonal elements
		// as per formula.
	}
	vector<vector<int>> temp(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		matrix[i][i]=degree[i];
	}
	create(temp,matrix,0,0,n);
	cout<<cofactor(temp,n-1)<<endl;

}