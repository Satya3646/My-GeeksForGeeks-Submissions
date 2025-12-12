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
    Node* insert(Node* root, int val) {
        //  code  here
        Node* node = new Node(val);
        if(!root)
            return node;
        Node* curr = root;
        while(curr != node) // When we attach the node to the tree iteration should end.
        {
            if(curr->data > val) // if current is greater the node belongs to its left.
            {
                if(!curr->left) // if a right doesnt exist then attach the node as right.
                    curr->left = node;
                curr = curr->left;
            }
            else // if current is smaller the node belongs to its right.
            {
                if(!curr->right) // if a left doesnt exist then attach the node as left.
                    curr->right = node;
                curr = curr->right;
            }
        }
        return root;
    }
};