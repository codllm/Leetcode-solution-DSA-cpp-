class Solution {
public:
    int minMoves(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int max = nums[nums.size()-1];
        int ans = 0;
        for(auto num:nums)
        {
            ans+=abs(num-max);
        }
        return ans;
    }
};