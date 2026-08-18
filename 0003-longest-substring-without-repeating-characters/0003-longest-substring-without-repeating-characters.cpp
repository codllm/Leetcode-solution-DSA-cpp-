class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<int,int>mpp;
        int left = 0;
        int maxlength = 0;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];

            if(mpp.find(ch)!=mpp.end())
            {
                //main ise dekhai hai phir muje dikha
                int seenindex = mpp[ch];
                left = max(left, seenindex + 1);
            }

            mpp[ch] = i;

            maxlength = max(maxlength,i-left+1);
        }
        return maxlength;
        
    }
};