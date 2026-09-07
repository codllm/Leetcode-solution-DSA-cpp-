class Solution {
    private:
    string rorate_by_ith(string& s,int i)
    {
        return s.substr(i)+s.substr(0,i);
    }
public:
    int countRotations(string s, int k) {

        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            string temp = rorate_by_ith(s,i);
            int cnt = 0;
            for(int j=1;j<s.size();j++)
            {
                if(temp[j] == temp[j-1]) cnt++;
            }

            if(cnt == k) ans++;
        }
        return ans;
        
    }
};