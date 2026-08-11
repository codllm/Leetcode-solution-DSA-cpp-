class Solution {
    private:
    bool dfs(vector<vector<int>>& adj,vector<bool>& visited,int source,int destination)
    {
        if(source == destination) return true;
        
        visited[source]= true;

        for(auto v:adj[source])
        {
            if(!visited[v])
            {
                if(dfs(adj,visited,v,destination)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>adj(n);

        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        
        return dfs(adj,visited,source,destination);
        
    }
};