class Solution {
    int dp[105][105];
    private:
    bool solve(string& s,int idx,int balanced)
    {
        if(balanced < 0) return false;   
        if(idx==s.size()) return balanced==0;

        if(dp[idx][balanced] != -1) return dp[idx][balanced];

        if(s[idx]=='(')
        {
            return dp[idx][balanced] = solve(s,idx+1,balanced+1);
        }
        else if(s[idx]==')')
        {
            return dp[idx][balanced] = solve(s,idx+1,balanced-1);
        }
      
            //has three case as '(' as "" as ')'
            return dp[idx][balanced] = solve(s,idx+1,balanced) || solve(s,idx+1,balanced+1) || solve(s,idx+1,balanced-1);
      

    }
public:
    bool checkValidString(string s) {

        //recursion+memo
        int balanced = 0;
        memset(dp,-1,sizeof(dp));
        return solve(s,0,balanced);
        
    }
};