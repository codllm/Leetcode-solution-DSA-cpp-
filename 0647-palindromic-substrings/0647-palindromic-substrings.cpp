class Solution {
    private:
    int expand_around_center(string s,int left,int right)
    {
        int count = 0;
        while(left>=0 && right<s.size() && s[left]==s[right] )
        {
            count++;
            left--;
            right++;
        }
        return count;     
    }
public:
    int countSubstrings(string s) {

        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            ans+=expand_around_center(s,i,i);
            ans+=expand_around_center(s,i,i+1);
        }
        return ans;
        
    }
};