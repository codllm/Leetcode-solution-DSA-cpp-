class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //question based on dijsktra algo
        //form graph
        vector<vector<pair<int,int>>>graph(n+1);

        for(auto time:times)
        {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            graph[u].push_back({v,wt});
        }

        vector<int>dist(n+1,INT_MAX);

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;

        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty())
        {
            auto [timeU,nodeU] = pq.top();
            pq.pop();

            for(auto [nodeV,timeV]:graph[nodeU])
            {
                if(timeU+timeV < dist[nodeV])
                {
                    dist[nodeV] = timeU+timeV;
                    pq.push({timeU+timeV,nodeV});
                }
            }
        }


        int ans=0;

        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX) return -1;//cannot reach to this place
            ans = max(ans,dist[i]);
        }
        return ans;
        
    }
};