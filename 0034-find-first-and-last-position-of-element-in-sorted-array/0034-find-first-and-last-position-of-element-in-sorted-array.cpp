class Solution {
    private:
    int firstoccurence(vector<int>& nums,int left,int right,int target)
    {
        int first = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(nums[mid]==target)
            {
                //first left side ofr better answer
                first = mid;
                right = mid-1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return first;
    }
    int lastoccurence(vector<int>& nums,int left,int right,int target)
    {
        int last = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(nums[mid]==target)
            {
                //first left side ofr better answer
                last = mid;
                left = mid+1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left =0;
        int right = nums.size()-1;
        int first = -1;
        int last = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(nums[mid]==target)
            {
                first = firstoccurence(nums,0,mid,target);
                last = lastoccurence(nums,mid,nums.size()-1,target);
                return {first,last};
            }
            else if(nums[mid]<target) left = mid+1;
            else right =mid-1;
        }

        return {-1,-1};
        
    }
};