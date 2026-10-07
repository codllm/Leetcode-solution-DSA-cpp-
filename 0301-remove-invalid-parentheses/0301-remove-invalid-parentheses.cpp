class Solution {
private:
    void solve(string& s, int idx, int openRemove, int closeRemove,
               int balance, string& temp, vector<string>& result)
    {
        // Base case
        if(idx == s.size())
        {
            if(openRemove == 0 && closeRemove == 0 && balance == 0)
            {
                result.push_back(temp);
            }
            return;
        }

        //taken
        if(s[idx] == '(')
        {
            temp.push_back(s[idx]);

            solve(s, idx + 1,
                  openRemove, closeRemove,
                  balance + 1,
                  temp, result);

            temp.pop_back();
        }
        else if(s[idx] == ')')
        {
            // We can take ')' when if there is it counter part ava
            if(balance > 0)
            {
                temp.push_back(s[idx]);

                solve(s, idx + 1,
                      openRemove, closeRemove,
                      balance - 1,
                      temp, result);

                temp.pop_back();
            }
        }
        else
        {
            // normal character must take it
            temp.push_back(s[idx]);

            solve(s, idx + 1,
                  openRemove, closeRemove,
                  balance,
                  temp, result);

            temp.pop_back();
        }
        
        //not taken
        if(s[idx] == '(' && openRemove > 0)
        {
            solve(s, idx + 1,
                  openRemove - 1, closeRemove,
                  balance,
                  temp, result);
        }

        if(s[idx] == ')' && closeRemove > 0)
        {
            solve(s, idx + 1,
                  openRemove, closeRemove - 1,
                  balance,
                  temp, result);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        int open = 0;
        int close = 0;

        // find minimum number of '(' and ')' to remove
        for(char ch : s)
        {
            if(ch == '(')
            {
                open++;
            }
            else if(ch == ')')
            {
                if(open > 0)
                    open--;
                else
                    close++;
            }
        }

        vector<string> result;
        string temp;

        solve(s, 0, open, close, 0, temp, result);

        // remove duplicates
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};