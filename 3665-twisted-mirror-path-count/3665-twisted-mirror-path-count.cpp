class Solution {
    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int dfs(vector<vector<int>>& grid, int i, int j, int dir)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;

        if(grid[i][j] == 1)
        {
            if(dir == 0) //0=down move
                ans = dfs(grid, i+1, j, 1);
            else //1==right move
                ans = dfs(grid, i, j+1, 0);
        }
        else
        {
            ans = (dfs(grid, i, j+1, 0) +
                   dfs(grid, i+1, j, 1)) % MOD;
        }

        return dp[i][j][dir] = ans;
    }

public:
    int uniquePaths(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return dfs(grid, 0, 0, 0);
    }
};