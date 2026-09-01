class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0;
        int right = nums.size()-1;

        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(mid%2==0)
            {//even
            //exactly appers one time appers on left side

            if(mid+1 < nums.size() && nums[mid]==nums[mid+1])
            {
                left = mid+2;
            }
            else right = mid-1;

            }
            else
            {
                //when mid is odd
                if(mid+1<nums.size() && nums[mid]!=nums[mid+1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return nums[left];
        
    }
};