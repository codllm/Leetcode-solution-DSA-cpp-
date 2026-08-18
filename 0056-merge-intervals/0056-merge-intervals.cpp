class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());

        int sttime = intervals[0][0];
        int endtime = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(endtime >= intervals[i][0])
            {
                endtime = max(endtime,intervals[i][1]);
            }
            else
            {
                ans.push_back({sttime,endtime});
                //update newtime

                sttime = intervals[i][0];
                endtime = intervals[i][1];
            }
        }

        ans.push_back({sttime,endtime});
        return ans;
        
    }
};