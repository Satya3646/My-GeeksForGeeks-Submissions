/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int ans = -1;
        while(root)
        {
            if(root->data < x)
            {
                ans = root->data;
                root = root->right;
            }
            else if(root->data > x)
                root = root->left;
            else
                return x;
        }
        return ans;
    }
};