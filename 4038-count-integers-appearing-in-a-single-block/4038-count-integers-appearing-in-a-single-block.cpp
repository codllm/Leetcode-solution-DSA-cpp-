class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int specialcount = 0;
        set<int>st;
        //using set because for uniq pair find only onces
        for(int i=0;i<nums.size();i++)
        {
            int firstocc = i;
            int lastocc = i;
            int howmany_same = 1;

            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i] == nums[j])
                {
                    lastocc = j;
                    howmany_same++;
                }
            }

            if(!st.count(nums[i]))//if i have not found for this interger then only 
            {
                if(lastocc-firstocc+1 == howmany_same) specialcount++;
            }
            st.insert(nums[i]);
                    
        }

        return specialcount;
        
    }
};