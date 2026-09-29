class Solution {
    private:
    bool ispalim(string& s,int l,int r)
    {
        while(l<r)
        {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string & s,int start,vector<string>& temp,vector<vector<string>>& result)
    {
        if(start == s.size()){
            result.push_back(temp);
            return;
        }

        for(int end=start;end<s.size();end++)
        {
            if(ispalim(s,start,end))
            {
                temp.push_back(s.substr(start,end-start+1));
                //
                solve(s,end+1,temp,result);
                temp.pop_back();
            }
        }

    }    
public:
    vector<vector<string>> partition(string s) {

        vector<string>temp;
        vector<vector<string>>result;
        solve(s,0,temp,result);

        return result;
        
    }
};