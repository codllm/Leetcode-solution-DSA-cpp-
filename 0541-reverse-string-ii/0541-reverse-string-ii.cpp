class Solution {
private:
    string solve(string s, int k)
    {
        if(s.empty())
            return "";

        // Base case: remaining string has at most 2*k characters
        if(s.size() <= 2*k)
        {
            int len = min(k, (int)s.size());
            reverse(s.begin(), s.begin() + len);
            return s;
        }

        string first = s.substr(0, 2*k);
        reverse(first.begin(), first.begin() + k);

        return first + solve(s.substr(2*k), k);
    }

public:
    string reverseStr(string s, int k) {
        return solve(s, k);
    }
};