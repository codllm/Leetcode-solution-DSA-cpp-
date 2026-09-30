class Solution {
public:
    int numRabbits(vector<int>& nums) {

        unordered_map<int,int>mpp;
        for(auto num:nums) mpp[num]++;

        int ans = 0;
        for (auto& [val, count] : mpp) {
            int groupSize = val + 1;
            // Ceiling division: (count + groupSize - 1) / groupSize
            //first +1 = group size;
            //second == no of element of diffent times of same group size
            //[2,2,2,2]-->1g[2,2,2] and 2g [2,also 2 other belongs to this group but not asked with tem]
            int nofgroup = ceil((double)count / groupSize);
            ans += nofgroup * groupSize;
        }
        return ans;
        
    }
};