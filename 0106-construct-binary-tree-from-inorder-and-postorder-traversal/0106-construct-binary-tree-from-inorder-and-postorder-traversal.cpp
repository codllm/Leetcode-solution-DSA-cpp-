/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* Tree_from_in_post_order(vector<int>& inorder, vector<int>& postorder,int& idx,int start,int end)
    {
        if(start>end) return nullptr;

        int nodeval = postorder[idx--];
        TreeNode* rootnode = new TreeNode(nodeval);

        int j = 0;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == nodeval)
            {
                j = i;
                break;
            }
        }
        rootnode->right = Tree_from_in_post_order(inorder,postorder,idx,j+1,end);
        rootnode->left = Tree_from_in_post_order(inorder,postorder,idx,start,j-1);

        return rootnode;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        int start = 0;
        int end = inorder.size()-1;
        return Tree_from_in_post_order(inorder,postorder,idx,start,end);
        
    }
};