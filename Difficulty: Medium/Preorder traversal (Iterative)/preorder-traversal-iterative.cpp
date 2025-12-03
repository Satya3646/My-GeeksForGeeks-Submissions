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
        stack <Node*> stk; // Stack to mimic call stack
        vector <int> ans;
        if(!root) // if tree is empty return empty answer
            return ans;
        stk.push(root); // Put root in stack to start traversal
        while(!stk.empty())
        {
            Node *node = stk.top(); // Extract the top node
            stk.pop();
            ans.push_back(node->data); // Put the value into the answer
            if(node->right) // Put the right node into stack since it needs to be evaluater later than the left node
                stk.push(node->right);
            if(node->left) // Put the left node on top of the right node since it need to be evaluated first
                stk.push(node->left);
        }
        return ans;
    }
};