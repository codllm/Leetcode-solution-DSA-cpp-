class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto it:mpp)
        {
            if(it.second.size()!=3) continue;
            vector<int> temp = it.second;

            int gap1 = temp[1] - temp[0];
            int gap2 = temp[2] - temp[1];

            if (gap1 == gap2)
                count++;
        }
        return count;
        
    }
};