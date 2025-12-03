/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        stack <Node*> stk;
        vector <int> ans;
        if(!root)
            return ans;
        stk.push(root);
        while(!stk.empty())
        {
            Node *node = stk.top();
            stk.pop();
            ans.push_back(node->data);
            if(node->right)
                stk.push(node->right);
            if(node->left)
                stk.push(node->left);
        }
        return ans;
    }
};