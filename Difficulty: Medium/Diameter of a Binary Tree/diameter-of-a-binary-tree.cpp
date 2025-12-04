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
    int solve(Node *root, int &dia)
    {
        if(!root)
            return 0;
        int l = solve(root->left, dia); // Height of the left subtree
        int r = solve(root->right, dia); // Height of the right subtree
        dia = max(dia, l + r); // Update diameter
        return 1 + max(l, r); // return height till now
    }

    int diameter(Node* root) {
        int dia = 0;
        solve(root, dia); // Call function to calculate the diamater as we calculate the height
        return dia;
    }
};