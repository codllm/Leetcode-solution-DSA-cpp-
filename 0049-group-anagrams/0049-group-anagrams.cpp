class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>mpp;

        for(auto str:strs)
        {
            string sortstr = str;

            sort(sortstr.begin(),sortstr.end());
            mpp[sortstr].push_back(str);
        }

         vector<vector<string>>result;

        for(auto m:mpp)
        {
            result.push_back(m.second);
        }

        return result;
        
    }
};