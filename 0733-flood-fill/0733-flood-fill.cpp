class Solution {
    private:
    void dfs(vector<vector<int>>& image,vector<vector<bool>>& visited, int sr, int sc, int color,int row,int col,int parentColor)
    {
        if(sr<0 || sr>=row || sc<0 || sc>=col) return; //(out-of boundary region)
        if(image[sr][sc]!=parentColor || visited[sr][sc]==true) return; //(alredy-marked visited or its color not matches with the neigbour cell)
        
        int originalColor=image[sr][sc];// its orginal cell color
        if(image[sr][sc]==parentColor) image[sr][sc]=color; //cell color changes to the given color of question
        visited[sr][sc]=true; //marked-visited

        //cell for its neighbour cell
        dfs(image,visited,sr+1,sc,color,row,col,originalColor);
        dfs(image,visited,sr-1,sc,color,row,col,originalColor);
        dfs(image,visited,sr,sc+1,color,row,col,originalColor);
        dfs(image,visited,sr,sc-1,color,row,col,originalColor);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));

        int row=image.size();
        int col=image[0].size();
        int parentColor=image[sr][sc];
        dfs(image,visited,sr,sc,color,row,col,parentColor);
        //return same images by modifing this
        return image;
        
    }
};