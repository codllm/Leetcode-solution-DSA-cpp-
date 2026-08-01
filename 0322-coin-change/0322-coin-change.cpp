class Solution {
    private:
    long solve(vector<int>& coins,int idx,int amount,vector<vector<int>>& dp)
    {
        if(amount < 0 || idx>=coins.size()) return INT_MAX;

        if(amount == 0) return 0;

        //for every coins i have two choice either take it or not take it

        if(dp[idx][amount] != -1) return dp[idx][amount];
        //taken       
        long taken = 1+ solve(coins,idx,amount - coins[idx],dp);


        //not taken
        long nottaken = solve(coins,idx+1,amount,dp);

        return dp[idx][amount] =  min(taken,nottaken);
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;
         vector<vector<int>> dp(
            coins.size(),
            vector<int>(amount + 1, -1)
        );
        long ans = solve(coins,0,amount,dp);

        return (ans >= INT_MAX) ? -1 : ans;
        
    }
};