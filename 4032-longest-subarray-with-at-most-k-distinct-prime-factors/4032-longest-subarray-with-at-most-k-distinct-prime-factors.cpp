#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getPrimeFactor(int num) {
        vector<int> ans;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                ans.push_back(i);        // Store only distinct prime factors
                while (num % i == 0)
                    num /= i;
            }
        }

        if (num > 1)
            ans.push_back(num);

        return ans;
    }

public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        // Store prime factors for each element
        vector<vector<int>> primeFactor(n);

        for (int i = 0; i < n; i++) {
            primeFactor[i] = getPrimeFactor(nums[i]);
        }

        unordered_map<int, int> mpp;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {

            // Add prime factors of current element
            for (auto pf : primeFactor[right]) {
                mpp[pf]++;
            }

            // Shrink window if distinct prime factors > k
            while (mpp.size() > k) {

                for (auto pf : primeFactor[left]) {
                    mpp[pf]--;

                    if (mpp[pf] == 0)
                        mpp.erase(pf);
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};