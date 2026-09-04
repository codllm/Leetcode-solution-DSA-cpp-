class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        //brute force approuch solution
        int max_i =nums[0];

        for(int i=0;i<nums.size();i++)
        {
            max_i = max(max_i,nums[i]);

            int min_i = nums[i]; 

            for(int j=i;j<nums.size();j++)
            {
                min_i = min(min_i,nums[j]);
            }
            if(max_i - min_i <= k) return i;
        }

        return -1;
        
    }
};