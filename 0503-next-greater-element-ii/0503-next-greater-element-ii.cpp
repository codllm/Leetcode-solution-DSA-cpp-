class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        stack<int>st;
        vector<int>result(n,-1);
        for(int i=0;i<n*2;i++)
        {
            //index using mod
            while(!st.empty() && nums[st.top()]<nums[i%n])
            {
                result[st.top()] = nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i);
        }
        return result;
        
    }
};