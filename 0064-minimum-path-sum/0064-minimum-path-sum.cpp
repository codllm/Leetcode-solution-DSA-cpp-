class Solution {
    private:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
        int r = grid.size();
        int c = grid[0].size();

        //out of region of grid so return
        if(i<0 || i>= r || j<0 || j>=c) return INT_MAX;

        if(i == r-1 && j == c-1) return grid[i][j];
        //reach the bottom right then returm with sum

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(grid,i+1,j,dp);
        int right =  solve(grid,i,j+1,dp);
        
        int ans = INT_MAX;
        if(down != INT_MAX)
        {
            ans = min(ans, down + grid[i][j]);
        }
        if(right != INT_MAX)
        {
            ans = min(ans, right + grid[i][j]);
        }

        return dp[i][j] = ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>>dp(r,vector<int>(c,-1));
        //dp memori that store min from the i and j

        return solve(grid,0,0,dp);
        
    }
};