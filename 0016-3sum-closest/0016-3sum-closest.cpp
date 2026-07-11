class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            int sum = 0;

            while( j < k)
            {
                sum = nums[i] + nums[j] + nums[k];

                if( sum == target) return sum;

                if(abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
                if(sum < target)
                {
                    j++;
                }
                else k--;

            }
        }

        return ans;
        
    }
};