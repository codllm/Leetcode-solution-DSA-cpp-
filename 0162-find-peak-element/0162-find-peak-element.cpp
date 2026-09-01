class Solution {
public:
    int findPeakElement(vector<int>& nums) {


        int left = 1;
        int right = nums.size()-1;
        int n = nums.size();

        if(n-1==0) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        //edges case also check it
        //of left side
        if(nums[0] < nums[1] && nums[1]>nums[2]) return 1;

        //of right side
        if(nums[n-3] < nums[n-2] && nums[n-2]>nums[n-1]) return n-2;


        while(left<=right)
        {
            int mid = left+(right-left)/2;

            //left<<mid>>right
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;

            //incresing slop--->
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
            {
                left = mid+1;
            }
            else
            {
                //mid at the decresing slop
                right = mid-1;
            }
        }

        //if no peak found return -1
        return -1;
        
    }
};