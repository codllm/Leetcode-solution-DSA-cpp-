class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int>st;
        for(auto num:nums) st.insert(num);
        int ans = 0;
        for(auto num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int count = 1;
                while(st.count(num+1))
                {
                    count++;
                    num++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
        
    }
};