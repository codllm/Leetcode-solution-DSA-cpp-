class Solution {
    private:
    bool solve(string &target, string &ans, bool isGreater,
           map<char,int> &mpp, int idx)
{
    if(idx == target.size())
        return isGreater;

    for(auto &it : mpp)
    {
        char ch = it.first;

        if(it.second == 0)
            continue;

        if(!isGreater && ch < target[idx])
            continue;

        it.second--;

        ans.push_back(ch);

        bool greater = isGreater || (ch > target[idx]);

        if(solve(target, ans, greater, mpp, idx + 1))
            return true;

        ans.pop_back();
        it.second++;
    }

    return false;
}
public:
    string lexGreaterPermutation(string s, string target) {

        map<char,int>mpp;
        //freq count
        for(auto ch:s)
        {
            mpp[ch]++;
        }

        string ans="";

        bool isGreater = false;

        if(solve(target,ans,isGreater,mpp,0)) return ans;

        return "";
        
    }
};