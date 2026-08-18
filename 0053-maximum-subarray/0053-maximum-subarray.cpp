class Solution {
public:
    int maxS(vector<int>&nums,int left,int right)
    {
        if(right==left) return nums[left];
        
            int mid=left+(right-left)/2;
            int maxLeftSum=maxS(nums,left,mid);
            int maxRightSum=maxS(nums,mid+1,right);

            int sum=0;
            int leftSum = INT_MIN, rightSum = INT_MIN;
            for(int j=mid;j>=left;j--)     //for the max sum from the left side
            {
                sum+=nums[j];
                leftSum=max(sum,leftSum);
            }
            sum=0;
            for(int j=mid+1;j<=right;j++)
            {
                sum+=nums[j];
                rightSum=max(sum,rightSum);

            }

           return max(max(maxLeftSum, maxRightSum), leftSum + rightSum);
        
    }
    int maxSubArray(vector<int>& nums) {

        return maxS(nums,0,nums.size()-1);
        
    }
};