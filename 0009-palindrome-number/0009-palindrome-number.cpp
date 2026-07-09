class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) return false;

        if(x % 10 == 0 && x != 0)
            return false;

        double rev = 0;
        double ini = x;

        while(x > 0)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return rev == ini;
    }
};