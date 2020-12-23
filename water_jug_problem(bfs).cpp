#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
	int x,y,t;
	cin>>x>>y>>t;
	// x is the limit of water jug 1 can hold and y for jug 2
	queue<pair<int,int>> q;
	// queue for storing levels of each jug
	q.push({0,0});
	v.push_back(q.front());
	vector<pair<int,int>> ans;
	// ans for storing the path
	vector<vector<bool>> visited(x+1,vector<bool>(y+1,false));
	while(!q.empty()){
		int x1=q.front().first,y1=q.front().second;
		q.pop();
		if(!visited[x1][y1]){
			visited[x1][y1]=true;
		}
		else{
			// if it is already visited
			continue;
		}
		ans.push_back({x1,y1});
		if((x1==t && y1==0) || (x1==0 && y1==t)){
			break;
			// if got out target then stop
		}
		if(x1==t && y1==y)
		{
			q.push({t,0});
			// if jug1 has target value and jug2 is full then we will empty jug2
		}	
		if(x1==x && y1==t)
		{
			q.push({0,t});
			// if jug2 has target value and jug1 is full then we will empty jug1
		}
		if(x1==0)
		{
			q.push({x,y1});
			// filling jug1
		}
		if(y1==0)
		{
			q.push({x1,y});
			//filling jug2
		}
		if(x1>0){
			// transfering from jug1 to jug2
			if(x1+y1>y){
				// if while transfering water to another it becomes full and still have some
				// water left to transfer
				q.push({x1-(y-y1),y});
			}
			else{
				// if all the water can be transfered to another jug
				q.push({0,y1+x1});
			}
		}
		if(y1>0)
		{
			// transfering from jug2 to jug1
			if(y1+x1>x){
				// same as previous
				q.push({x,y1-(x-x1)}); 
			}
			else{
				// same as previous
				q.push({x1+y1,0});
			}
		}
	}
	for(auto i:ans)
	{
		// printing the path to reach target value
		cout<<i.first<<" "<<i.second<<endl;
	}
}