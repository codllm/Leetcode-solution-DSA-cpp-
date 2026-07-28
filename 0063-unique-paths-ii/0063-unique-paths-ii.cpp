class Solution {
    private:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>& dp)
    {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

        //out of boundary region + obstacle in grid
        if(i<0 || i>=r || j<0 || j>=c || obstacleGrid[i][j] == 1) return 0;

        if(i == r-1 && j == c-1) return 1;//means one path found

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(obstacleGrid,i+1,j,dp);
        int right = solve(obstacleGrid,i,j+1,dp);

        return dp[i][j] = down + right;
       
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        //here dynamic array declear for track memoriza top-bottom approuch

        return solve(obstacleGrid,0,0,dp);
        
    }
};