class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int currXor,
            vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        currXor ^= grid[i][j];

        if (i == m - 1 && j == n - 1)
            return currXor;

        if (dp[i][j][currXor] != -1)
            return dp[i][j][currXor];

        int right = INT_MAX;
        int down = INT_MAX;

        if (j + 1 < n)
            right = dfs(grid, i, j + 1, currXor, dp);

        if (i + 1 < m)
            down = dfs(grid, i + 1, j, currXor, dp);

        // This recurrence is still not valid for minimum XOR:
        // right/down return final XOR values, not comparable costs.
        return dp[i][j][currXor] = min(right, down);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, -1))
        );

        return dfs(grid, 0, 0, 0, dp);
    }
};