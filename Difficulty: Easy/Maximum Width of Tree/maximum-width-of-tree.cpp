/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    int maxWidth(Node* root) {
        // code here
        int ans = 0;
        if(!root)
            return ans;
        queue <Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            ans = max(ans, n);
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};