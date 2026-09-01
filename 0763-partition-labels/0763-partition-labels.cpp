class Solution {
public:
    vector<int> partitionLabels(string s) {

        map<char,int>lastseen;

        for(int i=0;i<s.size();i++)
        {
            lastseen[s[i]] = i;
            // store last index of seen charecter
        }

        int end=0;
        int j=0;
        vector<int>paritionIndex;
        for(int i=0;i<s.size();i++)
        {
            end=max(end,lastseen[s[i]]);

            if(i==end)
            {
                paritionIndex.push_back(i-j+1);
                j=i+1;    
            }

        }

        return paritionIndex;

        
    }
};