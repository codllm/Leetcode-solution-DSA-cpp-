class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        //now ill write the solution based on the
        //bottom-up solution
        // in this approcuh ill write to move to the dp[0][0] case so that i can just return dp[0][0]

        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        //dp array mein triangle ka last row ko copy krdo

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int sameith = dp[i+1][j];
                int diffith = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] +  min(sameith,diffith);
            }
        }

        return dp[0][0];
        
    }
};