class Solution {
private:
    int waysToDecode(string &s, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ways = waysToDecode(s, i + 1, dp);

        if (i + 1 < s.size())
        {
            int num = stoi(s.substr(i, 2));

            if (num >= 10 && num <= 26)
            {
                ways += waysToDecode(s, i + 2, dp);
            }
        }

        return dp[i] = ways;
    }

public:
    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);

        return waysToDecode(s, 0, dp);
    }
};