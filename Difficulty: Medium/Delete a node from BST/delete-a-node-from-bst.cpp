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
    Node* delNode(Node* root, int key) {
        // code here
        if(!root)
            return root;
        if(root->data > key) // key exists in left subtree or the root.
            root->left = delNode(root->left, key); 
        else if(root->data < key) // key exists in the right subtree of the root.
            root->right = delNode(root->right, key);
        else // Current node is the node to be deleted.
        {
            if(!root->left) // if no left subtree then just return the right subtree deleting the root.
            {
                Node* r = root->right;
                delete root;
                return r;
            }
            else if(!root->right) // if no left subtree then just return the right subtree deleting the root.
            {
                Node* l = root->left;
                delete root;
                return l;
            }
            else // find the successor in the right subtree of the root.
            {
                Node* succ = root->right;
                while(succ->left)
                    succ = succ->left;
                root->data = succ->data; // Assign the value of the successor to the root.
                root->right = delNode(root->right, succ->data); // Next we need to delete the successor node.
            }
        }
        return root;
    }
};