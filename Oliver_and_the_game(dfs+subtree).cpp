#include<bits/stdc++.h>
using namespace std;
vector<int> in,out;
int timer=0;
void dfs(int i,vector<vector<int>> &adj,vector<int> &in,vector<int>& out)
{
    in[i]=timer++;
    // for setting time of visit
    for(int u:adj[i])
    {
        dfs(u,adj,in,out);
    }
    // for setting time of exit
    out[i]=timer++;
}
bool possible(int x,int y)
{
    // checking whether the y node is contained in the subtree of x node
    if(in[x]<in[y] && out[x]>out[y]){
        return true;
    }
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
    }
    // in and out are used to store the range of a node
    // all the nodes in the subtree of this node will fall under the range of given node
    in.resize(n+1),out.resize(n+1);
    dfs(1,adj,in,out);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,x,y;
        // y is your current position and x is the target node 
        scanf("%d%d%d",&a,&x,&y);
        // if none of them are in subtree of each other then it can't be reached
        if(!possible(x,y) && !possible(y,x)){
            printf("NO\n");
            continue;
        }
        // if y is present in the subtree of x
        // when going upwards 
        if(a==0){
            if(possible(x,y))
                printf("YES\n");
            else
                printf("NO\n");
        }
        // if x is present in the subtree of y
        // when going downwards
        else{
            if(possible(y,x))
                printf("YES\n");
            else
                printf("NO\n");

        }
    }

}