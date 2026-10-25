
class Solution {
private:
    bool dfs_solve(vector<vector<int>>& grid, int row, int col, int i, int j)
    {
        if(i < 0 || i >= row || j < 0 || j >= col)
            return false;

        if(grid[i][j] == 1)
            return true;

        grid[i][j] = 1; // Mark land as visited

        bool down  = dfs_solve(grid, row, col, i + 1, j);
        bool up    = dfs_solve(grid, row, col, i - 1, j);
        bool right = dfs_solve(grid, row, col, i, j + 1);
        bool left  = dfs_solve(grid, row, col, i, j - 1);

        return down && up && right && left;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 0)
                {
                    if(dfs_solve(grid, row, col, i, j))
                        ans++;
                }
            }
        }

        return ans;
    }
};
