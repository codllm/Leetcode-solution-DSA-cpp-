class Solution {
    private:
    int solve(vector<vector<char>>& matrix,int i,int j,vector<vector<int>>& dp)
    {
        int r = matrix.size();
        int c = matrix[0].size();

        if(i>=r || j>=c || matrix[i][j]=='0') return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(matrix,i,j+1,dp);
        int down = solve(matrix,i+1,j,dp);
        int diag = solve(matrix,i+1,j+1,dp);

        dp[i][j] = 1 + min({right, down, diag});
        
        return dp[i][j];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;
        
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        int maxsq = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                //it has form at least of one size
                if(matrix[i][j] == '1')
                {
                    maxsq = max(maxsq, solve(matrix, i, j, dp));
                }
            }
        }

        return maxsq * maxsq;
        
    }
};