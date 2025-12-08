/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* lca(Node* root, int p, int q) {
        //  code here
        if(!root)
            return nullptr;
        if(root->data == p || root->data == q) // Current node is one of target to return the current node since it will backtrack to find the LCA.
            return root;
        Node* l = lca(root->left, p, q); // Search the left subtree.
        Node* r = lca(root->right, p, q); // Search the right subtree.
        if(l && r) // If both searches resulted in a node then current node is the LCA.
            return root;
        if(l) // If only left subtree resulted in a node then both p & q are in left subtree only hence return 'l'.
            return l;
        return r; // If right subtree has p & q or both null case return the 'r'.
    }
};