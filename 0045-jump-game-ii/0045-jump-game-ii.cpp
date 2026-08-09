class Solution {
public:
    int jump(vector<int>& nums) {

        int lastjumpidx = 0;
        int maxreachidx = 0;
        int minstep = 0;

        for (int i = 0; i < nums.size()-1; i++) {

            maxreachidx = max(maxreachidx, i + nums[i]);

            if (i == lastjumpidx) {
                minstep++;
                lastjumpidx = maxreachidx;
            }
        }

        return minstep;
    }
};