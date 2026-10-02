/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* solve(Node* node,unordered_map<Node*,Node*>& mpp)
    {
        if(node==nullptr) return nullptr;
        if(mpp.find(node)!=mpp.end()) return mpp[node];
        //node return ho gya;

        //otherwise create the node and store in map
        Node* newnode = new Node(node->val);
        mpp[node] = newnode;

        newnode->next=solve(node->next,mpp);
        newnode->random= solve(node->random,mpp);

        return newnode;
    }
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*>mpp;
        return solve(head,mpp);
        
    }
};