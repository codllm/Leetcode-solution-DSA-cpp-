class Solution {
    int paths = 0;
    private:
    void  solve(vector<vector<int>>& grid,int i,int j,int row,int col,int remain)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==-1 || grid[i][j]==-2) return;

        if(grid[i][j] == 2)
        {
            if(remain == 1) paths++;
        }

        //backtracking
        int temp = grid[i][j];
        grid[i][j] = -2;

        solve(grid,i+1,j,row,col,remain-1);
        solve(grid,i-1,j,row,col,remain-1);
        solve(grid,i,j+1,row,col,remain-1);
        solve(grid,i,j-1,row,col,remain-1);

        //backtracking
        grid[i][j] = temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        int stindex;
        int endindex;
        int remain = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]!=-1) remain++;

                if(grid[i][j]==1)
                {
                    stindex = i;
                    endindex = j;     
                }
            }
        }

        solve(grid,stindex,endindex,row,col,remain);
        return paths;
        
    }
};