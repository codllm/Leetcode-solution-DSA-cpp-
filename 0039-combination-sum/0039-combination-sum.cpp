class Solution {
    private:
    void solve(vector<int>& candidates,int idx,int target,vector<int>& temp,vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return ;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(candidates[i]>target) continue;
            //can be taken candidates[i]<target
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                solve(candidates,i,target-candidates[i],temp,result);
                temp.pop_back();
            }
            //not be taken skip
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        //backtracking problem
        vector<int>temp;
        vector<vector<int>>result;
        solve(candidates,0,target,temp,result);
        return result;
        
    }
};