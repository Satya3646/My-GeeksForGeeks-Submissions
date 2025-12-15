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
    Node* LCA(Node* root, Node* p, Node* q) {
        if(!root)
            return nullptr;
        int curr = root->data,
            P = p->data,
            Q = q->data;
        if(P < curr && Q < curr) // Search the left subtree only since both are less than root.
            return LCA(root->left, p, q);
        if(P > curr && Q > curr) // Search the right subtree only since both are greater then root.
            return LCA(root->right, p, q);
        return root; // In other cases current node will be the LCA of given nodes.data
    }
};