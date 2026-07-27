class Solution {
    private:
    int solve(string sequence,string word,int idx,vector<int>& dp)
    {
        int n = sequence.size();
        int m = word.size();

        if(idx + m > n) return 0;

        if(dp[idx] != -1) return dp[idx];

        bool matchfound = true;

        for(int i=0;i<m;i++)
        {
            if(sequence[i + idx] != word[i])
            {
                matchfound = false;
                break;
            }
        }

        if(matchfound == false)
        {
            dp[idx]=0;
            return 0;
        }
        return dp[idx] = 1 + solve(sequence,word,idx+m,dp);

    }
public:
    int maxRepeating(string sequence, string word) {

        int n = sequence.size();
        vector<int>dp(n+1,-1);

        int maxcount = 0;
        for(int i=0;i<sequence.size();i++)
        {
            maxcount = max(maxcount,solve(sequence,word,i,dp));     
        }
        return maxcount;
        
    }
};