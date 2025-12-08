/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool solve(Node* left, Node* right) // Function to check if two trees are mirrors of each other or not.
    {
        if(left && right)
        {
            if(left->data != right->data)
                return false;
            /* 
            if two trees are to be called mirror images of eachother, left subtree of tree1 and 
            right subtree of tree2 must be mirrors and right subtree of tree1 and left subtree of 
            tree2 must also be mirrors.
            */
            return solve(left->left, right->right) && 
                   solve(left->right, right->left);
        }
        return left == right;
    }
    bool isSymmetric(Node* root) {
        if(!root)
            return true;
        return solve(root->left, root->right);
    }
};