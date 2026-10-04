class Solution {
public:
    bool checkValidString(string s) {

        int left=0;
        int n=s.size();

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '*') left++;
            else left --;
            if(left < 0) return false;
        }
        
        

        int right=0;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ')' || s[i] == '*') right++;
            else right--;

            if(right < 0) return false;
        }
        

        return true;

        
    }
};