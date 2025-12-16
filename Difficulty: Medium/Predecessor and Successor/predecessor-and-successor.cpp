/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector <Node*> findPreSuc(Node* root, int key) {
        // code here
        
        vector <Node*> ans = {nullptr, nullptr};
        Node* curr = root;
        while(curr)
        {
            if(curr->data < key) // if current is less than key then it can be the predecessor so update and and go right to find a larger node that can be the predecessor.
            {
                ans[0] = curr;
                curr = curr->right;
            }
            else // current node is greater than the key so go left to find the predecessor.
                curr = curr->left;
        }
        curr = root;
        while(curr)
        {
            if(curr->data > key) // if current is greater than key then it can be the successor so update and and go left to find a smaller node that can be the successor.
            {
                ans[1] = curr;
                curr = curr->left;
            }
            else // current node is smaller than the key so go right to find the successor.
                curr = curr->right;
        }
        return ans;
    }
};