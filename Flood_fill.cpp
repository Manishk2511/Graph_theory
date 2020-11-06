class Solution {
public:
    int n,m;
    bool possible(int i,int j,int colour,vector<vector<int>> &image)
    {
        if(i<0 || j<0 || i==n || j==m || image[i][j]!=colour)
        {
            return false;
        }
        return true;
    }
    void dfs(int i,int j,int colour,int newColour,vector<vector<bool>> &visited,vector<vector<int>> &image){
        if(i<0 || j<0 || i==n || j==m || visited[i][j] || image[i][j]!=colour)
        {
            return;
        }
        image[i][j]=newColour;
        visited[i][j]=true;
        if(possible(i+1,j,colour,image) && !visited[i+1][j])
        {
            dfs(i+1,j,colour,newColour,visited,image);
        }
        if(possible(i,j+1,colour,image) && !visited[i][j+1])
        {
            dfs(i,j+1,colour,newColour,visited,image);
        }   
        if(possible(i-1,j,colour,image) && !visited[i-1][j])
        {
            dfs(i-1,j,colour,newColour,visited,image);
        }
        if(possible(i,j-1,colour,image) && !visited[i][j-1])
        {
            dfs(i,j-1,colour,newColour,visited,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        if(n==0)
        {
            return image;
        }
        m=image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(sr,sc,image[sr][sc],newColor,visited,image);
        return image;
    }
};