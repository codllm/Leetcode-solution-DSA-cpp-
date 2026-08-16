class Solution {
    private:
    int getnextPos(vector<int>& nums, int i)
    {
    int n = nums.size();
    return ((i + nums[i]) % n + n) % n;
    }
public:
        bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

    for (int i = 0; i < n; i++) {

        bool sign = nums[i] > 0;

        set<int> visited;

        int cur = i;

        while (true) {

            int next = getnextPos(nums, cur);

            // self loop not allowed
            if (next == cur)
                break;

            // direction changed
            if ((nums[next] > 0) != sign)
                break;

            // cycle found
            if (visited.count(next))
                return true;

            visited.insert(next);

            cur = next;
        }
    }

    return false;

        
    }
};