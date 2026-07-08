class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;
        vector<string> zigzagString(numRows);
        int i = 0;

        while(i < s.size())
        {
            // Down
            for(int j = 0; j < numRows && i < s.size(); j++)
            {
                zigzagString[j].push_back(s[i]);
                i++;
            }
            
            // 0 to numRows (forward on goind) --> backward oncoming (numRows-2 to > 0)

            // Up diagonally
            for(int k = numRows - 2; k > 0 && i < s.size(); k--)
            {
                zigzagString[k].push_back(s[i]);
                i++;
            }
        }
        string ans = "";
        for(auto &row : zigzagString)
        {
            ans += row;
        }

        return ans;
    }
};