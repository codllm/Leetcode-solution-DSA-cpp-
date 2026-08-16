class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int prefix = 0;

        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            nums[i] = prefix;
        }
        return nums;
        
    }
};