class Solution {
public:
    int maxDepth(string s) {

        int inclose=0;
        int maxdepth=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                inclose++;
                maxdepth=max(maxdepth,inclose);
            }

            if(s[i] == ')') inclose--;
        }
        return maxdepth;
        
    }
};