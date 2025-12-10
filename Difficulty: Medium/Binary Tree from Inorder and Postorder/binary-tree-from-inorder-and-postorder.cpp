/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* helper(vector <int> &postorder, int pL, int pR, vector <int> &inorder, int iL, int iR, unordered_map <int, int> &rootLookup)
    {
        if(pL > pR || iL > iR)
            return nullptr;
        Node* root = new Node(postorder[pR]);
        int k = rootLookup[postorder[pR]];
        // iL to k-1 will be left subtree inorder.
        // k+1 to iR will be right subtree inorder.
        int leftSize = k-iL;
        // pL to pL+leftSize-1 is left subtree postorder.
        // pL+leftSize to pR-1 is right subtree postorder.
        root->left = helper(postorder, pL, pL+leftSize-1, inorder, iL, k-1, rootLookup);
        root->right = helper(postorder, pL+leftSize, pR-1, inorder, k+1, iR, rootLookup);
        return root;
    }

    Node* buildTree(vector <int> &inorder, vector <int> &postorder)
    {
        int n = postorder.size();
        unordered_map <int, int> rootLookup; // Map to instantly lookup root index.
        for(int i = 0; i < n; i++)
            rootLookup[inorder[i]] = i;
        return helper(postorder, 0, n-1, inorder, 0, n-1, rootLookup);;
    }
};