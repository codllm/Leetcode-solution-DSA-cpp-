
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            unordered_map<int, int> orderMap;

            int order = 1;
            int mismatch = 0;

            for (int j = i; j < n; j++) {
                int num = nums[j];

                if (mpp[num] > 0) {
                    int ord = orderMap[num];

                    // Remove the old mismatch status
                    if (mpp[num] != ord)
                        mismatch--;
                } else {
                    // Assign order to a new number
                    orderMap[num] = order++;
                }

                mpp[num]++;

                // Add the new mismatch status
                if (mpp[num] != orderMap[num])
                    mismatch++;

                if (mismatch == 0)
                    count++;
            }
        }

        return count;
    }
};
