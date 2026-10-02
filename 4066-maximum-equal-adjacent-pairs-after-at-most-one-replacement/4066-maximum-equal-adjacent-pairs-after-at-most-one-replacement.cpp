class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        int base = 0;
        map<pair<int,int>, int> mp;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            int x = nums[i];
            int y = nums[i + 1];

            if(x == y)
            {
                base++;
            }
            else
            {
                mp[{x, y}]++;
                mp[{y, x}]++;
            }
        }

        int extra = 0;

        for(auto it : mp)
        {
            extra = max(extra, it.second);
        }

        return base + extra;
    }
};