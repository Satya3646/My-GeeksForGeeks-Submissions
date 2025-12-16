/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class info
{
public :
    bool isBST; 
    int low, high;
    int size;
    
    info(int size, bool isBST, int low, int high)
    {
        this->size = size;
        this->isBST = isBST;
        this->low = low;
        this->high = high;
    }
};

class Solution {
  public:
    info solve(Node* root)
    {
        if(!root)
            return info(0, true, INT_MAX, INT_MIN);
        info l = solve(root->left);
        info r = solve(root->right);
        if(l.isBST && r.isBST &&
           l.high < root->data && 
           root->data < r.low)
            return info(l.size + r.size + 1, true, min(l.low, root->data), max(r.high, root->data));
        return info(max(l.size, r.size), false, 0, 0);
    }
    
    int largestBst(Node *root) {
        // Your code here
        return solve(root).size;
    }
};