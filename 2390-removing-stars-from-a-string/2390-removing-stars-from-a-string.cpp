class Solution {
public:
    string removeStars(string s) {

        string ans="";

        for(auto ch:s)
        {
            if(ch != '*') ans.push_back(ch);
            else
            {
                if(ans.length()>=1 && ch=='*')
                {
                    ans.pop_back();
                }
            }
        }
        return ans;
        
    }
};