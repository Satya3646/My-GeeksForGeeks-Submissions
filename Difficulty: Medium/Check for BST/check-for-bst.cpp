/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isBST(Node* root, long long l = LLONG_MIN, long long r = LLONG_MAX)
    {
        // code here
        if(!root) // Empty tree is always a valid BST
		return true;
    	if(l >= root->data || root->data >= r) // If root is out of range return false.
    		return false;
    	// Validate the left and right subtrees.
    	// Left subtree must strictly have all values less than root.
    	// Right subtree must strictly have all values greater than root.
    	return isBST(root->left, l, root->data) && isBST(root->right, root->data, r);
    }
};