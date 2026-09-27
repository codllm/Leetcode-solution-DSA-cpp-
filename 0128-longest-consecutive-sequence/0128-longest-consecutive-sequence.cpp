class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (auto num : s) {
            if (s.find(num - 1) == s.end()) { // start
                int x = num;
                int count = 1;

                while (s.find(x + 1) != s.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
