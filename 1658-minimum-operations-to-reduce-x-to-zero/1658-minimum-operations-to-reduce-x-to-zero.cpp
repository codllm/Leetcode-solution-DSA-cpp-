class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        unordered_map<int,int>mpp;
        int sum = 0;
        mpp[0] = -1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mpp[sum] = i;
        }

        if(sum<x) return -1;
        int remainsum = sum-x;
        int longestSub = INT_MIN;

        sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int findSum = sum-remainsum;
            if(mpp.count(findSum))
            {
                int findidx = mpp[findSum];
                longestSub = max(longestSub,i-findidx);         
            }
        }

        return longestSub==INT_MIN ? -1 : n-longestSub;
        
    }
};