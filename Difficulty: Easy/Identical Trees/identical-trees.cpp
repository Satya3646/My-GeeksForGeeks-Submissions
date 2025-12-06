/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* p, Node* q) {
        // code here
        if(!p & !q) // if both are null they are identical.
            return true;
        if((p && !q) || (!p && q)) // if only one of them is null the not identical.
            return false;
        if(p->data != q->data) // Check their values.
            return false;
        // Next check if the left and right subtrees are identical or not.
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
};