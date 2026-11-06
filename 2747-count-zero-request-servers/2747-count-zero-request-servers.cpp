class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int qSize = queries.size();
        
    
        vector<pair<int, int>> sortedQueries(qSize);
        for (int i = 0; i < qSize; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Log ka time index 1 par hota hai
        });
        
        vector<int> ans(qSize);
        unordered_map<int, int> serverFreq; // Window ke andar kis server ki kitni requests hain
        
        int left = 0, right = 0;
        int totalLogs = logs.size();
        
        for (int i = 0; i < qSize; i++) {
            int qTime = sortedQueries[i].first;
            int origIdx = sortedQueries[i].second;
            
            int start = qTime - x;
            int end = qTime;
            
            // Jo logs window ke right boundary (end) ke andar aate hain, unhe add karo
            while (right < totalLogs && logs[right][1] <= end) {
                serverFreq[logs[right][0]]++;
                right++;
            }
            
            // Jo logs window ke left boundary (start) se peeche ho gaye, unhe hatao
            while (left < totalLogs && logs[left][1] < start) {
                serverFreq[logs[left][0]]--;
                if (serverFreq[logs[left][0]] == 0) {
                    serverFreq.erase(logs[left][0]);
                }
                left++;
            } 
            // Zero-request servers = Total servers (n) - Unique active servers in map
            ans[origIdx] = n - serverFreq.size();
        }
        
        return ans;
    }
};