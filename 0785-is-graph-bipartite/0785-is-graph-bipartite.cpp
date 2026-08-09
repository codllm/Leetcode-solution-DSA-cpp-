class Solution {
    private:
    bool dfs(int u,int curntColor,vector<vector<int>>& graph,vector<int>& color)
    {
        color[u]=curntColor;

        for(auto v:graph[u])
        {
            if(color[v] == curntColor) return false;

            if(color[v] == -1)
            {
                if(dfs(v,1-curntColor,graph,color)==false) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        //umarked color =-1
        //one color =1
        //another color =0

        vector<int>color(graph.size(),-1);

        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if( dfs(i,0,graph,color) == false) return false;
            }
        }
        return true;
        
    }
};