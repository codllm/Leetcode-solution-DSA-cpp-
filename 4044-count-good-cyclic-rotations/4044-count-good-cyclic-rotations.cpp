class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size();

        int goodratation = 0;
        long long sttime = 0;
        for(int i=0;i<n/2;i++)
        {
            sttime = sttime + nums[i];
        }
        ////
        long long endtime = 0;
        for(int i=n/2;i<n;i++)
        {
            endtime = endtime + nums[i];
        }
        ////
        int left = 0;
        int right = n/2;

        for(int i=0;i<nums.size();i++)
        {
            if(sttime > endtime) goodratation++;

            sttime = sttime + nums[right] - nums[left];
            endtime = endtime + nums[left] - nums[right];

            left = (left+1)%n;
            right = (right+1)%n;
        }

        return goodratation;
        
    }
};