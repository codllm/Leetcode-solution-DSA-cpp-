/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mpp)
    {
        //node mil gya toh return krdo
        if(mpp.find(node)!=mpp.end()) return mpp[node];

        //agar nhi mila toh
        Node* newnode = new Node(node->val);

        mpp[node] = newnode;

        for(auto v:node->neighbors)
        {
            newnode->neighbors.push_back(dfs(v,mpp));     
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*>mpp;
        return dfs(node,mpp);
        
    }
};