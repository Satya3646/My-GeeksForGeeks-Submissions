/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector <int> ans;
        if(!root)
            return ans;
        // We need the rightmost node for different y level. 
        // BFS gives us the left to right traversal order while gradually increasing y level hence we can just take the last node value at each level and push it to answer.
        queue <Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(i == 0)
                    ans.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};