class Solution {
public:
    int countStaircase(vector<int>& nums) {

        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int order = 1;
            unordered_map<int,int>mpp;//num-->freq
            unordered_map<int,int>ordermap; //num-->order
            int mismatch = 0;
            for(int j=i;j<nums.size();j++)
            {
                int num = nums[j];

                if(mpp[num]>0)
                {
                    //alredy seen element
                    int ord = ordermap[num];

                    if(mpp[num]!=ord)
                    {
                        mismatch--;
                    }
                }
                else
                {
                    ordermap[num] = order; //num-->order
                    order++;

                }
                mpp[num]++; //map mpp ko increse freq  

                //freq same hona chahiye order k according

                if(mpp[num]!=ordermap[num])
                mismatch++;

                if(mismatch==0)
                count++;
            }
        }
        return count;
    }
};