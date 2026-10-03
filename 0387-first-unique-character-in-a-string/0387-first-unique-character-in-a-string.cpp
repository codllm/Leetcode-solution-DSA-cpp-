class Solution {
public:
    int firstUniqChar(string s) {

        map<int,int>mpp;
        for(auto ch:s) mpp[ch]++;
        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]]==1) return i;
        }
        return -1;
        
    }
};