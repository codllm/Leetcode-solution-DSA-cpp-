class Solution {
    private:
    void dfs(vector<vector<int>>& graph,vector<int>& temp,vector<vector<int>>& result,int source,int target)
    {
        temp.push_back(source);
        
        if(source == target)
        {
            result.push_back(temp);
        }
    
        //element ko push kiya temp mein
        for(auto v:graph[source])
        {
            dfs(graph,temp,result,v,target);
        }

        temp.pop_back();//again i pop that same elemnt
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        // have to find path from source to target
        // i have alredy given the graph
        //ismein visited ki jarurat nhi padegi

        int n = graph.size();
        vector<int>temp;
        vector<vector<int>>result;

        dfs(graph,temp,result,0,n-1);

        return result;
        
    }
};