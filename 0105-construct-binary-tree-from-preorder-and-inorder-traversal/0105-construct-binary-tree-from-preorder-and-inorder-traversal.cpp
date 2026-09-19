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
    TreeNode* TreeFrom_Pre_IN_order(vector<int>& preorder, vector<int>& inorder,int& idx,int left,int right)
    {
        if(left>right) return nullptr;

        int nodeval = preorder[idx++];
        TreeNode* rootnode = new TreeNode(nodeval);

        int j = 0;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == nodeval)
            {
                j = i;
            }
        }
        rootnode->left = TreeFrom_Pre_IN_order(preorder,inorder,idx,left,j-1);
        rootnode->right = TreeFrom_Pre_IN_order(preorder,inorder,idx,j+1,right);

        return rootnode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = inorder.size()-1;
        int idx = 0;
        return TreeFrom_Pre_IN_order(preorder,inorder,idx,left,right);
        
    }
};