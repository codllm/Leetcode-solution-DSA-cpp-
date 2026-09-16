class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]].push_back(i);
        }
        //
        int count = 0;
        for(auto it:mpp)
        {
            if(it.second.size()<3) continue;

            vector<int>temp = it.second;

            //for loop for each (it constain) vector
            int gap = temp[1] - temp[0];
            bool flag = true;//assume
            for(int i=1;i<temp.size();i++)
            {
                if(temp[i] - temp[i-1] != gap)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;

    }
};