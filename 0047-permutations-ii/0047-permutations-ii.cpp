class Solution {
    private:
    void solve(vector<int>nums,vector<int>& temp,vector<vector<int>>& result,vector<bool>& visited)
    {
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == false) continue;
            if(visited[i]==true) continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            solve(nums,temp,result,visited);

            visited[i]=false;
            temp.pop_back();

        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<bool>visited(nums.size(),false);
        vector<vector<int>>result;
        solve(nums,temp,result,visited);
        return result;
    }
};