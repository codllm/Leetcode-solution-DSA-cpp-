class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        //sort the string ok
        int n=strs.size();
        string s1=strs[0];
        string s2=strs[n-1]; 

        int i=0;

        string prefix="";
        while(i < s1.size() && i < s2.size() && s1[i] == s2[i])
        {
            prefix+=s1[i];
            i++;
        }

        return prefix;

        
    }
};