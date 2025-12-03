/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void postOrder(Node *root, vector <int> &ans)
    {
        if(root == nullptr)
            return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        // code here
        vector <int> order;
        postOrder(root, order);
        return order;
    }
};