class Solution {
public:
    int minMoves(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int min_val = nums[0];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(nums[i] - min_val);
        }
        return ans;
        
    }
};