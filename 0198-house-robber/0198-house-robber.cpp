class Solution {
    private:
    int robber(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i>=nums.size()) return 0;
        //taken

        if(dp[i] != -1) return dp[i];
        int taken = nums[i] + robber(nums,i+2,dp);

        //not taken
        int nottaken = robber(nums,i+1,dp);

        return dp[i] = max(taken , nottaken);
    }
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        //one basic idea is that take or not take concept use
        //if number is taken then peform i+2 otherwise i+1

        vector<int>dp(nums.size()+1,-1);
        return robber(nums,0,dp);
        
    }
};