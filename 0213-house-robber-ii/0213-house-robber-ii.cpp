class Solution {
private:
    int solve(vector<int>& nums, int start, int end)
    {
        int size = end - start + 1;

        if (size == 1)
            return nums[start];

        vector<int> dp(size);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < size; i++)
        {
            int take = dp[i - 2] + nums[start + i];
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[size - 1];
    }

public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n - 2);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};