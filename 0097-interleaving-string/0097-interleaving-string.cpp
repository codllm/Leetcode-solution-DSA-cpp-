class Solution {
private:
    bool solve(string &s1, string &s2, string &s3,
               int i, int j, int k,
               vector<vector<int>> &dp)
    {
        // Base case
        if (k == s3.size())
            return (i == s1.size() && j == s2.size());

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Both match
        if (i < s1.size() &&
            j < s2.size() &&
            s1[i] == s3[k] &&
            s2[j] == s3[k])
        {
            return dp[i][j] =
                solve(s1, s2, s3, i + 1, j, k + 1, dp) ||
                solve(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        // Only s1 matches
        if (i < s1.size() && s1[i] == s3[k])
        {
            return dp[i][j] =
                solve(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        // Only s2 matches
        if (j < s2.size() && s2[j] == s3[k])
        {
            return dp[i][j] =
                solve(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        // Neither matches
        return dp[i][j] = false;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1));

        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};