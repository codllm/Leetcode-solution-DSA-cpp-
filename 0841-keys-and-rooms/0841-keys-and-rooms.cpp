class Solution {
    private:
    void dfs(vector<vector<int>>& rooms,vector<bool>& visitedrooms,int roomKey)
    {
        visitedrooms[roomKey] = true;//iss room ka key mil gya hai marked it as open

        //ab muje iss room se-->jis bhi other rooms ka key milega take it and marked it has true

        for(auto newroomkey : rooms[roomKey])
        {
            if(!visitedrooms[newroomkey])
            {
                dfs(rooms,visitedrooms,newroomkey);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool>visitedrooms(n,false);

        dfs(rooms,visitedrooms,0);

        for(int i=0;i<n;i++)
        {
            if(visitedrooms[i] == false) return false;
        }
        return true;
        
    }
};