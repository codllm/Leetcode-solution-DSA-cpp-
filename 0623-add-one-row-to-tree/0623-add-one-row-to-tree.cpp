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
    TreeNode* solve(TreeNode* root, int val, int depth) {

        if (root == nullptr)
            return nullptr;

        // We have reached the parent of the target depth
        if (depth == 1) {

            // Save the original children for reconeccting them
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            // Create two new nodes left and right at that level
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            // Connect them the parent root node
            root->left = leftNode;
            root->right = rightNode;

            // Attach the old children
            leftNode->left = leftTemp;
            rightNode->right = rightTemp;

            return root;
        }

        solve(root->left, val, depth - 1);
        solve(root->right, val, depth - 1);

        return root;
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // insert above the root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return solve(root, val, depth - 1);
    }
};