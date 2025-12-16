/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void correctBST(Node* root) {
        // add code here.
        Node* first = nullptr;
        Node* second = nullptr;
        Node* curr = root;
        Node* prev = nullptr;
        while(curr)
        {
            if(curr->left) // if a left subtree exists then find the last node in left subtree and attach the right pointer of that node to current node(root).
            {
                Node* pred = curr->left;
                while(pred->right && pred->right != curr) // find inorder predecessor.
                    pred = pred->right;
                if(!pred->right) // link doesnt exist.
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else // link exists so break it since traversal completed.
                {
                    pred->right = nullptr;
                    // Visit the current node since its the root being visited after completion of left subtree.
                    if(prev && curr->data < prev->data)
                    {
                        if(!first) // if its the first inversion.
                        {
                            first = prev;
                            second = curr;
                        }
                        else // if second inversion is encountered then update only the second
                            second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
            else // if a left subtree doesnt exist then visit and go right.
            {
                // Visit the current node.
                if(prev && curr->data < prev->data)
                {
                    if(!first) // if its the first inversion.
                    {
                        first = prev;
                        second = curr;
                    }
                    else // if second inversion is encountered then update only the second
                        second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        swap(first->data, second->data);
    }
};