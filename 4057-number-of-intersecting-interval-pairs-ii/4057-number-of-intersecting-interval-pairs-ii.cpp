class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<int> sttime;

        for(auto it : intervals)
        {
            sttime.push_back(it[0]);
        }

        long long cnt = 0;

        for(int i = 0; i < n; i++)
        {
            int pos = upper_bound(
                sttime.begin() + i + 1,
                sttime.end(),
                intervals[i][1]
            ) - sttime.begin();

            cnt += pos - i - 1;
        }

        return cnt;
    }
};