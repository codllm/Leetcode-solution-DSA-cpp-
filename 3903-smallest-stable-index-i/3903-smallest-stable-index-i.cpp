class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        //optimal code time n space0(n)--solution
        
        vector<int>greater;

        int max_i = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            max_i = max(max_i, nums[i]);

            greater.push_back(max_i);
        }

        int n = nums.size();
        vector<int>smaller;
        int min_i = nums[n-1];
        for(int i=n-1;i>=0;i--)
        {
            min_i = min(min_i,nums[i]);

            smaller.push_back(min_i);
        }
        reverse(smaller.begin(),smaller.end());

        for(int i=0;i<smaller.size();i++)
        {
            if(greater[i] - smaller[i] <= k) return i;
        }
        return -1;
        
    }
};