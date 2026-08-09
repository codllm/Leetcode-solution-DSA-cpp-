class Solution {
private:
    bool isConnected(int u, int v,
                     vector<bool>& visited,
                     vector<vector<int>>& adj)
    {
        if(u == v) return true;
        visited[u] = true;

        for(int nei : adj[u])
        {
            if(!visited[nei])
            {
                if(isConnected(nei, v, visited, adj))
                    return true;
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for(auto& e : edges)
        {
            int u = e[0];
            int v = e[1];

            vector<bool> visited(n + 1, false);

            if(isConnected(u, v, visited, adj))
                return e;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};