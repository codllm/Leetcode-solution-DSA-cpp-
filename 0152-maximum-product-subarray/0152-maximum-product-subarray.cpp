class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        long left = 1;
        long right = 1;

        long ans = nums[0];

        for (int i = 0; i < n; i++) {

            if (left == 0) left = 1;
            if (right == 0) right = 1;

            left *= nums[i];
            right *= nums[n - 1 - i];

            ans = max(ans, max(left, right));
        }

        return ans;
    }
};