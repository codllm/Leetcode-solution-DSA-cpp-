class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size())
    return -1;
        int m = needle.size();

        if(haystack.substr(0,m)==needle) return 0;

        for (int i = 0; i <= haystack.size() - m; i++) {
         if (haystack.substr(i, m) == needle)
        return i;
        }

        return -1;
    }
};