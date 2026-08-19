class Solution {
public:
    int lengthOfLastWord(string s) {

        int right = s.size()-1;

        while(right>=0 && s[right]==' ')
        {
            right--;
        }
        int j = right;

        while(j>=0 && s[j] != ' ')
        {
            j--;
        }

        return right-j;

    }
};