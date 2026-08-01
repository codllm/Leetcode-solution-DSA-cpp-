class Solution {
    private:
    int solve(vector<int>& coins,int amount,int idx,vector<vector<int>>& dp)
    {
        if(amount == 0) return 1;

        if(amount < 0 || idx>= coins.size()) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];
        //again same we have two choice for every coin either take it or not take it
        //form amount = 0 by taking or not taking it

        int taken = solve(coins,amount-coins[idx],idx,dp);

        int nottaken = solve(coins,amount,idx+1,dp);

        return dp[idx][amount] = taken + nottaken;
    }
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
        
    }
};