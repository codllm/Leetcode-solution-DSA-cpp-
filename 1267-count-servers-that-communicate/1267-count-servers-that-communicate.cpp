class Solution {
    private:
    int solve(vector<vector<int>>& grid,int i,int j,int row,int col)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0) return 0;

        grid[i][j] = 0;
        int ans = 1;
        for(int k=0;k<col;k++)
        {
            if(grid[i][k]==1)
            {
                ans+=solve(grid,i,k,row,col);
            }
        }

        for(int k=0;k<row;k++)
        {
            if(grid[k][j]==1)
            {
                ans+=solve(grid,k,j,row,col);
            }
        }
        return ans;
    }
public:
    int countServers(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int connection = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    int conn = solve(grid,i,j,row,col);
                    connection+=(conn>1) ? conn:0;
                }
            }
        }
        return connection;
        
    }
};