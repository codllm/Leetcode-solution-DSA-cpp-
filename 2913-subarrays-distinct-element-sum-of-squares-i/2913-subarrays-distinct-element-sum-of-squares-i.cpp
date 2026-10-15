class Solution {
public:
    int sumCounts(vector<int>& nums) {

        //generate sub-array
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            set<int>st;
            for(int j=i;j<nums.size();j++)
            {
                st.insert(nums[j]);
                int n = st.size();

                ans+=n*n;
            }
        } 

        return ans; 
    }
};