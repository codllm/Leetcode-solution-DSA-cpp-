class Solution {
public:
    Node* connect(Node* root) {

        if(root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<Node*> temp;

            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                Node* curr = q.front();
                q.pop();

                temp.push_back(curr);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            for(int i = 1; i < temp.size(); i++)
            {
                temp[i-1]->next = temp[i];
            }
        }

        return root;
    }
};