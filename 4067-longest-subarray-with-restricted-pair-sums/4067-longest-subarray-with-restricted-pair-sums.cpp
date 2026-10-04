class Solution {
private:
    bool invalid(unordered_map<int, int>& mpp, int c)
    {
        for (auto a : mpp)
        {
            // Case 1: c + a exists
            if (mpp.find(c + a.first) != mpp.end())
                return true;

            // Case 2: c - a exists
            int b = c - a.first;

            if (b >= 0 && mpp.find(b) != mpp.end())
            {
                if (b != a.first || mpp[b] >= 2)
                    return true;
            }
        }

        return false;
    }

public:
    int maxSubarray(vector<int>& nums)
    {
        unordered_map<int, int> mpp;

        int left = 0;
        int longestsub = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            // Remove elements until nums[right] can be added
            while (invalid(mpp, nums[right]))
            {
                mpp[nums[left]]--;

                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);

                left++;
            }

            // Now add current element
            mpp[nums[right]]++;

            longestsub = max(longestsub, right - left + 1);
        }

        return longestsub;
    }
};