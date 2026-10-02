class Solution {
    private:
    void solve(int n,int open,int close,string& temp,vector<string>& result)
    {
        if(temp.size()==2*n)
        {
            result.push_back(temp);
            return;
        }

        if(open < n)
        {
            temp.push_back('(');
            solve(n,open+1,close,temp,result);
            temp.pop_back();
        }
        if(close<open)
        {
            temp.push_back(')');
            solve(n,open,close+1,temp,result);
            temp.pop_back();
        }
        

    }
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string>result;
        string temp ="";
        solve(n,open,close,temp,result);
        return result;
        
    }
};