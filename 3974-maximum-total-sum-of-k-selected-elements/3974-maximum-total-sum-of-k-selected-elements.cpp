class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        long long totalSum = 0;

        sort(nums.begin(),nums.end());

        int i = nums.size()-1;//ith index pointer

        while(mul>0 && k>0)
        {
            totalSum = totalSum + (long long)nums[i]*mul;
            mul--;
            i--;
            k--;
        }
        while(k>0)
        {
            totalSum = totalSum + nums[i];
            k--;
            i--;      
        }
        return totalSum;
        
    }
};