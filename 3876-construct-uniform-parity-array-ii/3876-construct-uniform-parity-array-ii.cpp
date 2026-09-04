class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;

        for (int x : nums1)

            if (x % 2 != 0)
                mnOdd = min(mnOdd, x);

        for (int x : nums1)
            if (x % 2 == 0 && mnOdd != INT_MAX && x <= mnOdd)
                return false;

        return true;
    }
};