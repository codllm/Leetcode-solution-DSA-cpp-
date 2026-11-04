
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int p = it[2];

            graph[u].push_back({v, p});
        }

        vector<vector<int>> dist(k + 2, vector<int>(n, INT_MAX));

        dist[0][src] = 0;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0, src}});

        while(!pq.empty()) {

            auto [price, node] = pq.top();
            pq.pop();

            auto [curK, nodeU] = node;

            if(nodeU == dst) return price;

            if(curK == k + 1) continue;

            for(auto [vnode, vprice] : graph[nodeU]) {

                int newPrice = price + vprice;

                if(newPrice < dist[curK + 1][vnode]) {

                    dist[curK + 1][vnode] = newPrice;

                    pq.push({newPrice, {curK + 1, vnode}});
                }
            }
        }

        return -1;
    }
};
