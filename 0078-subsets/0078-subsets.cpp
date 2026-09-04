class Solution {
    private:
    void solve(vector<int>& nums,int idx,vector<int>& temp,vector<vector<int>>& result)
    {
        if(idx==nums.size())
        {
            result.push_back(temp);
            return;
        }

        //taken
        temp.push_back(nums[idx]);

        solve(nums,idx+1,temp,result);

        temp.pop_back(); //backtrack

        //not taken
        solve(nums,idx+1,temp,result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        //generate all possible subset
        //backtack -- taken not taken

        vector<int>temp;
        vector<vector<int>>result;
        solve(nums,0,temp,result);
        return result;
        
    }
};