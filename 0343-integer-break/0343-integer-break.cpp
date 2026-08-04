class Solution {
    vector<int> dp;

private:
    int solve(int n) {
        if (n == 1) return 1;

        if (dp[n] != -1)
            return dp[n];

        int result = INT_MIN;

        for (int i = 1; i < n; i++) {
            int product = i * max(n - i, solve(n - i));
            result = max(result, product);
        }

        return dp[n] = result;
    }

public:
    int integerBreak(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};