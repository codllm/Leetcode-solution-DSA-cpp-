class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans;

        while(!nums.empty())
        {
            vector<int> temp;
            unordered_set<int> st;

            for(int i = 0; i < nums.size(); i++)
            {
                if(!st.count(nums[i]))
                {
                    temp.push_back(nums[i]);
                    st.insert(nums[i]);
                }
            }

            sort(temp.begin(), temp.end());

            for(auto it : temp)
            {
                ans.push_back(it);

                // remove ONE occurrence
                for(int i = 0; i < nums.size(); i++)
                {
                    if(nums[i] == it)
                    {
                        nums.erase(nums.begin() + i);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};