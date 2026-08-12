class Solution {
private:

    int bfs(vector<vector<int>>& grid,
            
            int row,
            int col)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    
                }
            }
        }

        int minutes = 0;

        while(!q.empty())
        {
            int size = q.size();

            bool rotten = false;

            for(int i=0;i<size;i++)
            {
                auto node = q.front();
                q.pop();

                int m = node.first; 
                int n = node.second;

                // down
                if(m+1 >=0 && m+1 < row &&
                   n >=0 && n < col &&
                   grid[m+1][n] == 1)
                {
                    q.push({m+1,n});
                    grid[m+1][n] = 2;
                    rotten = true;
                }

                // up
                if(m-1 >=0 && m-1 < row &&
                   n >=0 && n < col &&
                   grid[m-1][n] == 1)
                {
                    q.push({m-1,n});
                    grid[m-1][n] = 2;
                    rotten = true;
                }

                // right
                if(m >=0 && m < row &&
                   n+1 >=0 && n+1 < col &&
                   grid[m][n+1] == 1)
                {
                    q.push({m,n+1});
                    grid[m][n+1] = 2;
                    rotten = true;
                }

                // left
                if(m >=0 && m < row &&
                   n-1 >=0 && n-1 < col &&
                   grid[m][n-1] == 1)
                {
                    q.push({m,n-1});
                    grid[m][n-1] = 2;
                    rotten = true;
                }
            }
            // minute increase only if something rotted
            if(rotten)
            {
                minutes++;
            }
        }
        // check fresh orange left or not
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return minutes;
    }

public:

    int orangesRotting(vector<vector<int>>& grid) {

       

        return bfs(grid,

                   grid.size(),
                   grid[0].size());
    }
};