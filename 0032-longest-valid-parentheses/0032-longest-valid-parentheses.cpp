class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>st;
        st.push(-1);
        int longestlen=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
               if(!st.empty())
               {
                st.pop();
                if(st.empty())
                {     
                    st.push(i);       
                }
                else longestlen=max(longestlen,i-st.top()); 
               }
               
            }
            else st.push(i);
            
        }

        return longestlen;        
    }
};