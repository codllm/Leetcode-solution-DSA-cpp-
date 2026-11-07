class Solution {
public:
    typedef pair<int, int> p;
    // {weight, index}

    typedef tuple<long long, int, int> t;
    // {finishTime, weight, index}

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<p, vector<p>, greater<p>> freeServers;

        priority_queue<t, vector<t>, greater<t>> busyServers;

        vector<int> result(m);

        // Initially, all servers are free
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        for (int i = 0; i < m; i++) {

            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= i) {

                auto [finTime, wt, idx] = busyServers.top();

                busyServers.pop();

                freeServers.push({wt, idx});
            }
            if (freeServers.empty()) {

                auto [finTime, wt, idx] = busyServers.top();

                busyServers.pop();
                result[i] = idx;
                busyServers.push({
                    finTime + tasks[i],
                    wt,
                    idx
                });
            }
            else {

                auto [wt, idx] = freeServers.top();

                freeServers.pop();
                result[i] = idx;
                busyServers.push({
                    (long long)i + tasks[i],
                    wt,
                    idx
                });
            }
        }

        return result;
    }
};