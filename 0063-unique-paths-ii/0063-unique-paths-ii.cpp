class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp,
              int i, int j)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if(i < 0 || i >= row || j < 0 || j >= col ||
           obstacleGrid[i][j] == 1)
            return 0;

        if(i == row-1 && j == col-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(obstacleGrid, dp, i+1, j);
        int right = solve(obstacleGrid, dp, i, j+1);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        return solve(obstacleGrid, dp, 0, 0);
    }
};