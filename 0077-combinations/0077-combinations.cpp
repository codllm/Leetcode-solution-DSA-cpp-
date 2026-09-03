class Solution {
    private:
    void solve(int n,int idx, int k,vector<int>& temp,vector<vector<int>>& result)
    {
        if(temp.size() == k)
        {
            result.push_back(temp);
            return;
        }

        for(int i=idx;i<=n;i++)
        {
            temp.push_back(i);

            solve(n,i+1,k,temp,result);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int>temp;
        vector<vector<int>>result;
        solve(n,1,k,temp,result);
        return result;
        
    }
};