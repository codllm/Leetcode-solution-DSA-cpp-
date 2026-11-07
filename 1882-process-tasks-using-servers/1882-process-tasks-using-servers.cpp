class Solution {
public:
    typedef pair<int, int> p; 
    // {weight, index}

    typedef tuple<long long, int, int> t;
    // {free_time, weight, index}

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<p, vector<p>, greater<p>> freeServer;
        priority_queue<t, vector<t>, greater<t>> busyServer;

        vector<int> result(tasks.size());

        // Initially all servers are free
        for (int i = 0; i < servers.size(); i++) {
            freeServer.push({servers[i], i});
        }

        long long current_time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            current_time = max(current_time, (long long)i);

            // Free all servers which have completed their tasks
            while (!busyServer.empty() &&
                   get<0>(busyServer.top()) <= current_time) {

                auto [finishTime, weight, index] = busyServer.top();
                busyServer.pop();

                freeServer.push({weight, index});
            }

            // If no server is free, jump to earliest finish time
            if (freeServer.empty()) {

                current_time = get<0>(busyServer.top());

                // Free all servers that finish at this time
                while (!busyServer.empty() &&
                       get<0>(busyServer.top()) <= current_time) {

                    auto [finishTime, weight, index] = busyServer.top();
                    busyServer.pop();

                    freeServer.push({weight, index});
                }
            }

            // Now at least one server is free
            auto [weight, index] = freeServer.top();
            freeServer.pop();

            result[i] = index;

            busyServer.push({
                current_time + tasks[i],
                weight,
                index
            });
        }

        return result;
    }
};