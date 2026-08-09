class Solution {
    private:
    bool iscycleFormed(int u,int v,vector<vector<int>>& adj,vector<bool>& visited)
    {
        if(v==u) return true;
        visited[u] = true;

        for(auto nei:adj[u])
        {
            if(!visited[nei])
            {
                if(iscycleFormed(nei,v,adj,visited)) return true;      
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<vector<int>>adj(edges.size()+1);

        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(edges.size()+1, false);

            if(iscycleFormed(u,v,adj,visited)) return edge;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
        
    }
};