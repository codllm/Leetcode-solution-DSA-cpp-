class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int countOne = 0;
        string ans = "";

        for(int right=0;right<s.size();right++)
        {
            if(s[right]=='1') countOne++;

            while(countOne > k)
            {
                if(s[left]=='1')
                {
                    countOne--;
                }
                left++;
            }
            //one more while for removing the leading 0
            while (countOne == k && s[left] == '0')
                left++;

            if(countOne == k)
            {
                string cur = s.substr(left,right-left+1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans))
                    ans = cur;
            }
        }

        return ans;
        
    }
};