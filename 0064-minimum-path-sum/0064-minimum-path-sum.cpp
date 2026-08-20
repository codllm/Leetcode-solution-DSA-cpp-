class Solution {
    private:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col,int i,int j)
    {
        if(i<0 || i>=row || j<0 || j>=col) return INT_MAX;

        if(i==row-1 && j==col-1)
        {
            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        int down = solve(grid,dp,row,col,i+1,j);

        if(down != INT_MAX)
        {
            ans = min(ans,down);
        }
        int right = solve(grid,dp,row,col,i,j+1);

        if(right != INT_MAX)
        {
            ans = min(ans,right);
        }

        return dp[i][j] = ans + grid[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(grid,dp,row,col,0,0);
        
    }
};