class Solution {
    private:
    int solve(string& word1,string& word2,int i,int j,vector<vector<int>>& dp)
    {
        if(j == word2.size()) return word1.size()-i;
        //if charecter left from word1 or word2 then that much operation is needed for deleting right
        if(i == word1.size()) return word2.size()-j;

        //if both char is not same then i have 3 thing todo replace insert delete

        if(dp[i][j] != -1) return dp[i][j];

        //if both charecter matches then just move forward
        if(word1[i] == word2[j])
        {
            dp[i][j] = solve(word1,word2,i+1,j+1,dp);
            return dp[i][j];
        }
       
            int replace = 1 + solve(word1,word2,i+1,j+1,dp);
            //repace mein same char send karo

            int deletee = 1 + solve(word1,word2,i+1,j,dp);
            //delete mein pointer move kro

            int insert = 1 + solve(word1,word2,i,j+1,dp);
            //beach mein char push krna hai

            return dp[i][j] = min({replace,deletee,insert});

               
        
        
    }
public:
    int minDistance(string word1, string word2) {

        int i = 0;//track of word1
        int j = 0;//track of word2

        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));

        return solve(word1,word2,i,j,dp);
        
    }
};