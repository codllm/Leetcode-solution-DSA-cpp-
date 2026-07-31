class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size()) return -1;
        int m = needle.size();

        string ans = haystack.substr(0, m);

        if (ans == needle) return 0;

        int left = 1;

        for (int right = m; right < haystack.size(); right++) {

            ans.erase(0, 1);
            
            ans.push_back(haystack[right]);

            if (ans == needle) return left;

            left++;
        }

        return -1;
    }
};