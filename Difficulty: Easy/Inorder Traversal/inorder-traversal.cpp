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
    void inOrder(Node *root, vector <int> &ans)
    {
        if(root == nullptr)
            return;
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector <int> order;
        inOrder(root, order);
        return order;
    }
};