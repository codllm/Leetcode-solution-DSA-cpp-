class Solution {
private:
    double dfs(unordered_map<string, vector<pair<string, double>>>& adj,
               string src,
               string dest,
               double product,
               unordered_set<string>& visited)
    {
        if (src == dest)
            return product;

        visited.insert(src);

        for (auto& neighbour : adj[src])
        {
            string nextNode = neighbour.first;
            double weight = neighbour.second;

            if (!visited.count(nextNode))
            {
                double ans = dfs(adj, nextNode, dest,
                                 product * weight, visited);

                if (ans != -1.0)
                    return ans;
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> result;

        for (int i = 0; i < queries.size(); i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];

            if (adj.find(src) == adj.end() ||
                adj.find(dest) == adj.end())
            {
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            double ans = dfs(adj, src, dest, 1.0, visited);

            result.push_back(ans);
        }

        return result;
    }
};