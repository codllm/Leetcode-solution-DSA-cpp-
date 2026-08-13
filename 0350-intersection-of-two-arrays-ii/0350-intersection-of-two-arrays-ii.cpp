class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {


        //easiest you can solve this using the hashmap
        //space complex 0(n);
        //time complex 0(n)
        unordered_map<int,int>mpp;

        for(auto num:nums1)
        {
            mpp[num]++;
        }

        vector<int>ans;
        for(auto num:nums2)
        {
            if(mpp.find(num)!=mpp.end())
            {
                mpp[num]--;
                if(mpp[num]==0) mpp.erase(num);
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};