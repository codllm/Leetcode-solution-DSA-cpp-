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
    void allValidpath(TreeNode* root,int targetSum,vector<vector<int>>& result,vector<int>& temp)
    {
        if(!root) return;

        temp.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr && root->val==targetSum)
        {
            result.push_back(temp);
        }

        allValidpath(root->left,targetSum-root->val,result,temp);
        allValidpath(root->right,targetSum-root->val,result,temp);
        temp.pop_back();//pop last push element;
        // If we pop_back() in the middle, the left subtree is correct, but before going to the right subtree we remove the root from the path. The right subtree also needs the root in its path, so the answer becomes wrong.
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>result;
        vector<int>temp;

        allValidpath(root,targetSum,result,temp);
        return result;
        
    }
};