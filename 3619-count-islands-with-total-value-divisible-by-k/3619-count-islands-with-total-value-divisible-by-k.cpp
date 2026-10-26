class Solution {
    private:
    long long dfs_solve(vector<vector<int>>& grid,int row,int col,int i ,int j)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0) return 0;

        long long curnt_sum = grid[i][j];//store curnt land value
        grid[i][j] = 0; //mark as visited

        curnt_sum+=dfs_solve(grid,row,col,i-1,j);
        curnt_sum+=dfs_solve(grid,row,col,i+1,j);
        curnt_sum+=dfs_solve(grid,row,col,i,j-1);
        curnt_sum+=dfs_solve(grid,row,col,i,j+1);

        return curnt_sum;

    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {

        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    //finding count of island
                    long long count = dfs_solve(grid,row,col,i,j);
                    //check island count is divisible by k
                    if(count%k==0) ans++;
                }
            }
        }
        return ans;
    }
};