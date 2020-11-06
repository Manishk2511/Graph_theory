#include<bits/stdc++.h>
using namespace std;
#define MAX 5
vector<string> printPath(int m[MAX][MAX],int n);

bool possible(int i,int j,int m[MAX][MAX],int n,vector<vector<bool>> &visited)
{
    if(i<0 || j<0  || j>=n || i>=n ||m[i][j]==0 || visited[i][j])
        return false;
    return true;
    
}
void dfs(int i,int j,int m[MAX][MAX],int n,string &temp,vector<string> &s,vector<vector<bool>> &visited)
{
    if(i==-1|| i==n || j==-1 || j==n || visited[i][j] || m[i][j]==0 )
    {
        return;
    }
    if(i==n-1 && j==n-1)
    {
        s.push_back(temp);
        return;
    }
    else
    {
        visited[i][j]=true;
        if(possible(i+1,j,m,n,visited)){
            temp+='D';
            dfs(i+1,j,m,n,temp,s,visited);
            temp.pop_back();
        }
        if(possible(i,j-1,m,n,visited))
        {
            temp+='L';
            dfs(i,j-1,m,n,temp,s,visited);
            temp.pop_back();
        }
        if(possible(i,j+1,m,n,visited))
        {
            temp+='R';
            dfs(i,j+1,m,n,temp,s,visited);
            temp.pop_back();
        }
        if(possible(i-1,j,m,n,visited))
        {
            temp+='U';
            dfs(i-1,j,m,n,temp,s,visited);
            temp.pop_back();
        }
        visited[i][j]=false;
    }
    
}
// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> s;
    string temp="";
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    dfs(0,0,m,n,temp,s,visited);
    return s;
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
        int m[MAX][MAX];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>m[i][j];
            }
        }
        vector<string> ans=printPath(m,n);
        if(ans.size()==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(string s:ans)
            {
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }
}
