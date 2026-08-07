class Solution {
private:
    Node* dfs(Node* node, map<Node*, Node*>& mpp)
    {
        //node alredy found and that is part of mpp and it is connted with the someother node in graph is alredy created not connted--add this linked to it
        if (mpp.find(node) != mpp.end())
            return mpp[node];

        Node* newnode = new Node(node->val);
        //if that node not created and not part of the map cfeated that node and store into the map

        mpp[node] = newnode;

        for (auto v : node->neighbors)
        {
            //gives new conntection with the related node(newnode) in the graph of clone
            newnode->neighbors.push_back(dfs(v, mpp));
            //it also handel the bidirection connection bw the nodes
        }

        return newnode;
    }

public:
    Node* cloneGraph(Node* node) {

        if (node == nullptr)
            return nullptr;

        map<Node*, Node*> mpp;

        return dfs(node, mpp);
    }
};