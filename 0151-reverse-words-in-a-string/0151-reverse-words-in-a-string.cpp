class Solution {
    private:
    void reverse(string& ans,string& result)
    {
        if(result.empty())
        {
            result = ans;
        }
        else result = ans+" "+result;
    }
public:
    string reverseWords(string s) {

        string result = "";

        int i=0;
        while(i<s.size())
        {
            if(s[i]==' ') i++;
            else
            {
                string ans ="";

                while(i<s.size() && s[i]!=' ')
                {
                    ans+=s[i];
                    i++;
                }

                reverse(ans,result);
            }
        }
        return result;
        
    }
};