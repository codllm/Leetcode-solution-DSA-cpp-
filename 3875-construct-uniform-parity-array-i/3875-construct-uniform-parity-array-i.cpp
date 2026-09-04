class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int oddcount = 0;
        int evencount = 0;

        for (auto num : nums1) {
            if (num % 2 != 0)
                oddcount++;
            else
                evencount++;
        }

        // Already uniform
        if (oddcount == 0 || evencount == 0)
            return true;

        // Try to make all numbers odd
        for (int i = 0; i < n; i++) {

            if (nums1[i] % 2 != 0)
                continue;

            bool flag = false;

            // even - odd(j) = odd
            for (int j = 0; j < n; j++) {

                if (i != j &&
                    nums1[j] % 2 != 0) {

                    flag = true;
                    break;
                }
            }

            if (!flag)
                return false;
        }

        return true;
    }
};