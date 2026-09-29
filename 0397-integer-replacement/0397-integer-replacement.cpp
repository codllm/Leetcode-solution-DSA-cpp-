class Solution {
    private:
    int solve(long long n,unordered_map<long long, int>& dp)
    {
        if(n<1) return INT_MAX;
        if(n == 1) return 0;

        if(dp.count(n)) return dp[n];
        
        if(n%2==0)
        {
            return dp[n]=1+solve(n/2,dp);
        }

        return dp[n] = 1+min(solve(n+1,dp),solve(n-1,dp));
    }
public:
    int integerReplacement(int n) {

        if(n==2) return 1;
        unordered_map<long long, int> dp;
        return solve(n,dp);
        
    }
};