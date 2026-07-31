class Solution {
    private:
    int solve(string& word1,string& word2,int i ,int j,vector<vector<int>>& dp)
    {
        if(i == word1.size()) return word2.size()-j;
        //
        if(j == word2.size()) return word1.size()-i;


        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i] == word2[j])
        {
            return dp[i][j] = solve(word1,word2,i+1,j+1,dp);
        }

        //only delete operation i can do here i have two choice either do with w1 or w2
        int w1_w2 = 1+ solve(word1,word2,i+1,j,dp);
        int w2_w1 = 1+ solve(word1,word2,i,j+1,dp);

        return dp[i][j] = min(w1_w2,w2_w1);
    }


public:
    int minDistance(string word1, string word2) {

        if(word1.size() == 0 && word2.size()==0) return 0;

        //i have to make both word same so i can either make w1 to w2 or w2 to w1
        vector<vector<int>>dp(
            word1.size(),
            vector<int>(word2.size(),-1)
            );

        return solve(word1,word2,0,0,dp);      
    }
};