class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {

        // {destination, color}
        // "r" = red
        // "b" = blue
        vector<vector<pair<int, string>>> adj(n);

        // Red edges
        for (auto re : redEdges) {
            int u = re[0];
            int v = re[1];

            adj[u].push_back({v, "r"});
        }

        // Blue edges
        for (auto be : blueEdges) {
            int u = be[0];
            int v = be[1];

            adj[u].push_back({v, "b"});
        }

        // dist[node][color]
        //
        // dist[x][0] = shortest distance to x
        //               when the last edge was RED
        //
        // dist[x][1] = shortest distance to x
        //               when the last edge was BLUE
        //
        // 0 = red
        // 1 = blue

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));

        queue<pair<int, int>> q;

        // Start from node 0.
        //
        // We don't actually have a previous color.
        // So we allow both possibilities.
        q.push({0, 0}); // pretend previous color = red
        q.push({0, 1}); // pretend previous color = blue

        dist[0][0] = 0;
        dist[0][1] = 0;

        while (!q.empty()) {

            auto [prevNode, prevColor] = q.front();
            q.pop();

            for (auto [curNode, curColor] : adj[prevNode]) {

                // Convert string color to number
                int currentColor;

                if (curColor == "r")
                    currentColor = 0;
                else
                    currentColor = 1;

                // Same color -> cannot take this edge
                if (currentColor == prevColor)
                    continue;

                // Already visited this STATE
                if (dist[curNode][currentColor] != INT_MAX)
                    continue;

                dist[curNode][currentColor] =
                    dist[prevNode][prevColor] + 1;

                q.push({curNode, currentColor});
            }
        }

        vector<int> answer(n, -1);

        for (int i = 0; i < n; i++) {

            int best = min(
                dist[i][0],
                dist[i][1]
            );

            if (best != INT_MAX)
                answer[i] = best;
        }

        return answer;
    }
};