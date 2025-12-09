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
    bool isSumProperty(Node *root) {
        // code here
        if(!root) 
            return true;
        if(!root->left && !root->right) // Leaf is always valid
            return true;
        int target = 0;
        if(root->left)
            target += root->left->data;
        if(root->right)
            target += root->right->data;
        if(root->data != target)
            return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};