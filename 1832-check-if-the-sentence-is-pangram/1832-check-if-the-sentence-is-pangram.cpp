class Solution {
public:
    bool checkIfPangram(string sentence) {

        vector<int>english(26,false);

        for(int i=0;i<sentence.size();i++)
        {
            int idx = sentence[i]-97;

            if(english[idx]==true) continue;

            english[idx]=true;
        }
        for(int i=0;i<english.size();i++)
        {
            if(english[i]==false) return false;
        }
        return true;
        
    }
};