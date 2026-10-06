class Solution {
public:
    string simplifyPath(string path) {

        stringstream ss(path);
        string chunk;
        stack<string>st;
        while(getline(ss,chunk,'/'))
        {
            // /one //two //multiple treat--> as single/
            if(chunk=="." || chunk=="") continue;

            if(chunk=="..")
            {
                if(!st.empty()) st.pop();
            }
            else
            {
                st.push(chunk);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans='/'+ st.top()+ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
        
    }
};