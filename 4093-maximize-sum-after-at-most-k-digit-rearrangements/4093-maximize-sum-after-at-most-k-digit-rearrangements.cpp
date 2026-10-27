class Solution {
private:
    int getmaxnum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end(), greater<char>());
        return stoi(s);
    }

public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<int, int>> result;

        for (int num : nums) {
            int maxnum = getmaxnum(num);
            result.push_back({maxnum, num});
        }

        sort(result.begin(), result.end(),
             [](const auto& a, const auto& b) {
                 return (a.first - a.second) >
                        (b.first - b.second);
             });

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k)
                ans += result[i].first;
            else
                ans += result[i].second;
        }

        return ans;
    }
};