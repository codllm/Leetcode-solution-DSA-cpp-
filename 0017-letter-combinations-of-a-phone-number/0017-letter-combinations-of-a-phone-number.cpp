class Solution {
    private:
    string charecters(int x){
    switch(x)
    {
        case 1: return "";
        case 2: return "abc";
        case 3: return "def";
        case 4: return "ghi";
        case 5: return "jkl";
        case 6: return "mno";
        case 7: return "pqrs";
        case 8: return "tuv";
        case 9: return "wxyz";

        default: return "";
    }
}
    void solve(string& digits,int idx,string&  temp,vector<string>& result)
    {
        if(temp.size() == digits.size())
        {
            result.push_back(temp);
            return;
        }
        string s=charecters(digits[idx]-'0');

        for(int i=0;i<s.length();i++)
        {
            temp.push_back(s[i]);
            solve(digits,idx+1,temp,result);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        vector<string>result;
        string temp="";
        solve(digits,0,temp,result);
        return result;


    }
};