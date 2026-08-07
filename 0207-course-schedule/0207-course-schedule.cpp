class Solution {
    private:
    bool iscycle(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<bool>& recpath)
    {
        visited[u] = true;
        recpath[u] = true;

        for(auto v:adj[u])
        {
            if(!visited[v])
            {
                if(iscycle(adj,v,visited,recpath)) return true;
            }
            else
            {
                if(recpath[v]) return true;
            }
        }
        recpath[u] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //1.form directed-->graph
        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites)
        {
            int v = p[0];
            int u = p[1];
            
            adj[u].push_back(v);
        }

        vector<bool>visited(numCourses,false);

        for(int i=0;i<numCourses;i++)
        {
            vector<bool>recpath(numCourses,false);
            if(!visited[i])
            {
                if(iscycle(adj,i,visited,recpath)) return false;
            }
        }
        return true;
    }
};