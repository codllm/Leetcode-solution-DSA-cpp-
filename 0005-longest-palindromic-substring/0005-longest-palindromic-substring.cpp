class Solution {
public:

int palindromic(string &s, int left, int right)
{
    while(left >= 0 && right < s.size())
    {
        if(s[left] != s[right]) break;
        left--;
        right++;
    }

    return right - left - 1;
}

string longestPalindrome(string s) {

    int length = 0;
    int start = 0;
    int end = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int odd = palindromic(s, i, i);
        int even = palindromic(s, i, i + 1);

        int maxLen = max(odd, even);

        if(maxLen > length)
        {
            length = maxLen;

            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    return s.substr(start, end - start + 1);
}
};