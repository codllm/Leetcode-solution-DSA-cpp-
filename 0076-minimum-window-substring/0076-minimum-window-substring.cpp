class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size()<t.size()) return "";

        map<char,int>mpt;
        for(auto ch:t) mpt[ch]++;

        int tsize=mpt.size();
        int count=0;
        int minlen=INT_MAX;
        
        map<char,int>mps;
        int start=0;
        int left=0;
        for(int right=0;right<s.size();right++)
        {
            mps[s[right]]++;

            if(mps[s[right]]==mpt[s[right]]) count++;

            while(count==tsize)
            {
                if(minlen>right-left+1)
                {
                    minlen=right-left+1;
                    start=left;
                }
                mps[s[left]]--;
                if(mpt.count(s[left]) && mps[s[left]]<mpt[s[left]]) count--;
                left++;
            }     
        }

        return (minlen==INT_MAX) ? "" : s.substr(start,minlen);
        
    }
};