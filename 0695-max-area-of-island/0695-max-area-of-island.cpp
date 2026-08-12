class Solution {
    private:
    int dfs(vector<vector<int>>& grid,int row,int col,int i ,int j)
    {
       
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0) return 0;

        grid[i][j] = 0; //marked it as visted so it doesnot count into answer more than one time
        int ans = 0;

        int up =  dfs(grid,row,col,i-1,j);
        int down =  dfs(grid,row,col,i+1,j);
        int right =  dfs(grid,row,col,i,j+1);
        int left =  dfs(grid,row,col,i,j-1);
      
        ans = 1+ left + right + down + up;

        return ans;  
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int maxarea = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    //start dfs
                    maxarea = max(maxarea,dfs(grid,row,col,i,j));
                }
            }
        }
        return maxarea;
        
    }
};