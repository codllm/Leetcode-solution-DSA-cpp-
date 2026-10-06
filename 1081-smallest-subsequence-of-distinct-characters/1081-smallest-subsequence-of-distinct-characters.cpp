class Solution {
public:
    string smallestSubsequence(string s) {

                unordered_map<int,int>mpp;
        //store last occurance of each charec
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]=i;
        }

        //along with this i have to main-tain the set of used charecter
        set<char>used;
        //to main the seq stack needed

        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            // already present in stack
            if(used.count(s[i]))
                continue;

            while(!st.empty() && s[st.top()]>s[i] && i < mpp[s[st.top()]])
            {
                used.erase(s[st.top()]);
                st.pop();
            }

            used.insert(s[i]);
            st.push(i);
        }
        string ans="";
        while(!st.empty())
        {
            ans= s[st.top()]+ans;
            st.pop();
        }
        return ans;
        
    }
};