class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        map<int,int>mpp;

        for(auto it:items)
        {
            int p = it[0];
            int b = it[1];
            mpp[p] = max(mpp[p],b);
        }

        //prefix max ka khel horha ha
        //map automatically sorted manner mein value store krta ha
        //so store the prefix maximum beauty value
        int maxi = 0;
        for(auto &m:mpp)
        {
            maxi = max(maxi,m.second);
            m.second = maxi;
        }
        
        vector<int>ans;
        for(auto q:queries)
        {
            auto it = mpp.upper_bound(q);//just greate pointer return krta ha

            if(it==mpp.begin())
            {
                ans.push_back(0);
            }
            else
            {
                it--;
                ans.push_back(it->second);
            }
        }

        return ans;
        
    }
};