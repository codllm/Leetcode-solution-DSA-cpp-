class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr)
                    return level;
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            level++;
        }

        return level;
    }
};