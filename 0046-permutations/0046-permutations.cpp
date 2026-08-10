class Solution {
    private:
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result,vector<bool>& visited)
    {
        if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==true) continue;
            temp.push_back(nums[i]);
            //taken
            visited[i] = true;
            solve(nums,temp,result,visited);

            visited[i] = false;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>result;
        vector<int>temp;
        vector<bool>visited(nums.size(),false);
        solve(nums,temp,result,visited);

        return result;
    }
};