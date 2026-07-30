class Solution {
private:
    int solve(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp)
    {
        if (idx >= nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int taken = 0;

        if (prev == -1 || nums[prev] < nums[idx])
        {
            taken = 1 + solve(nums, idx + 1, idx, dp);
        }

        int skip = solve(nums, idx + 1, prev, dp);

        return dp[idx][prev + 1] = max(taken, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp);
    }
};