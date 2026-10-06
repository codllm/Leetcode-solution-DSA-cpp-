class Solution {
public:
    string decodeString(string s) {

        stack<int>stINT;
        stack<char>stChar;

        int num = 0;

        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i]=='[')
            {
                stChar.push(s[i]);
                stINT.push(num);
                num = 0;
            }
            else if(s[i]==']')
            {
                string temp ="";
                while(stChar.top()!='[')
                {
                    temp.push_back(stChar.top());
                    stChar.pop();
                }
                reverse(temp.begin(),temp.end());

                int count = stINT.top();
                stINT.pop();
                stChar.pop();
                string repeated = "";
                for(int i=0;i<count;i++)
                {
                    repeated+=temp;
                }
                //
                for(auto ch:repeated) stChar.push(ch);

            }
            else stChar.push(s[i]);
        }

        string result = "";

        while(!stChar.empty())
        {
            result+=stChar.top();
            stChar.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};