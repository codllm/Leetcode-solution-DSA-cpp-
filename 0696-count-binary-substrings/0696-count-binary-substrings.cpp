class Solution {
public:
    int countBinarySubstrings(string s) {

        int prevcount = 0;
        int curntcount = 1;
        int result = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1]) curntcount++;
            else
            {
                result+=min(prevcount,curntcount);
                prevcount = curntcount;
                curntcount = 1;
            }
        }
        return result+min(prevcount,curntcount);
        
    }
};