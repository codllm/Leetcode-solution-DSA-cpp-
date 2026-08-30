class Solution {
public:
    int findMin(vector<int>& nums) {

        //it is sure that after rotation atleast onehalf will be sorted
        
        int l = 0;
        int r = nums.size()-1;

        int ans = INT_MAX;

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(nums[mid] < nums[r])//sorted
            {
                ans = min(ans,nums[mid]);
                r = mid-1;
            }
            else
            {
                ans = min(ans,nums[l]);
                l = mid+1;
            }
        }
        return ans;
    
        
    }
};