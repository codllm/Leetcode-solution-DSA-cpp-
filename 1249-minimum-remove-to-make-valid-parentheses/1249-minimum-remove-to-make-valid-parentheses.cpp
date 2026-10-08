class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> openst;

        for(int i = 0; i < s.size(); i++)
        {
            if(openst.empty() && s[i] == ')') {
                s.erase(i, 1);
                i--; // fix the position of i
                continue;
            }

            if(s[i] == '(')
            {
                openst.push(i);
            }
            else if(s[i] == ')')
            {
                if(!openst.empty()) {
                    openst.pop();
                }
            }
        }

        while(!openst.empty())
        {
            int i = openst.top();
            openst.pop();
            s.erase(i, 1);
        }

        return s;
    }
};