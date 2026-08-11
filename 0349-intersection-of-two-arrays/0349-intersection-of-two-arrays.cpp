class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int>st;
        for(auto num:nums1)
        {
            st.insert(num);
        }

        vector<int>ans;
        for(auto num:nums2)
        {
            if(st.find(num)!=st.end())
            {
                ans.push_back(num);
                st.erase(num);
            }
        }
        return ans;
        
    }
};