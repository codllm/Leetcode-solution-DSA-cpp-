class Solution {
public:
    bool isPalindrome(string &str) {

        int left = 0;
        int right = str.size() - 1;

        while (left < right) {

            if (str[left] != str[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    int countSubstrings(string s) {

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            for (int j = i; j < s.size(); j++) {

                string sub = s.substr(i, j - i + 1);

                if (isPalindrome(sub))
                    ans++;
            }
        }

        return ans;
    }
};