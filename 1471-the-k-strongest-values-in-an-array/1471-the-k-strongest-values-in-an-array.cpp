class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int m = arr[(n - 1) / 2];

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n; i++)
        {
            int strength = abs(arr[i] - m);
            pq.push({strength, arr[i]});
        }

        vector<int> ans;

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};