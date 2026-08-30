class Solution {
private:
    int getminidex(vector<int>& nums)
    {
        int idx = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[idx])
                idx = i;
        }
        return idx;
    }

    int getmaxindex(vector<int>& nums)
    {
        int idx = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[idx])
                idx = i;
        }
        return idx;
    }

public:
    int minimumDeletions(vector<int>& nums) {

        int minindex = getminidex(nums);
        int maxindex = getmaxindex(nums);

        int n = nums.size();
        int mid = (n - 1) / 2;

        int left = max(minindex, maxindex) + 1;
        int right = n - min(minindex, maxindex);
        int both = min(minindex, maxindex) + 1 + n - max(minindex, maxindex);

        // Both on left half
        if(minindex <= mid && maxindex <= mid)
        {
            return left;
        }
        // Both on right half
        else if(minindex > mid && maxindex > mid)
        {
            return right;
        }
        // One on each side
        else
        {
            return min({left, right, both});
        }
    }
};