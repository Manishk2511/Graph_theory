// when you are not practicing, someone else is practicing.
// The day when you meet them, you will lose.


#include<bits/stdc++.h>
using namespace std;

class position{
public:
	int x,y,d;
	position(int x,int y,int d)
	{
		this->x=x,this->y=y,this->d=d;
	}
};

bool possible(int i,int j,int n)
{
	if(i<=0 || j<=0 || j>n || i>n)
	{
		return false;
	}
	return true;
}

void bfs(int i,int j,int k,int l,int n,vector<vector<bool>> &visited,int &MIN)
{
	int moves[2][8]={{-1,-2,1,2,-1,-2,1,2},
			   {-2,-1,2,1,2,1,-2,-1}};
	queue<position> q;
	q.push(position(i,j,0));
	visited[i][j]=true;
	while(!q.empty())
	{
		position p=q.front();
		if(p.x==k && p.y==l){
			MIN=min(p.d,MIN);
		}
		q.pop();
		for(int i=0;i<8;i++)
		{
			int row=p.x+moves[0][i];
			int col=p.y+moves[1][i];
			if(possible(row,col,n)&& !visited[row][col])
			{
				visited[row][col]=true;
				q.push(position(row,col,p.d+1));
			}
		}
	}
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
		int n;
		cin>>n;
		int i,j,k,l;
		cin>>i>>j>>k>>l;
		int MIN=INT_MAX;
		vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
		bfs(i,j,k,l,n,visited,MIN);
		cout<<MIN<<endl;
	}
}