/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to traverse the left boundary (except leaves).
    void left_boundary_traversal(Node* curr, vector <int> &ans)
    {
        while(curr)
        {
            if(curr->left || curr->right) // Push to ans only if current node is not a leaf.
                ans.push_back(curr->data);
            if(curr->left) // if a path to left is there go that way.
                curr = curr->left;
            else // go right if left path is not there.
                curr = curr->right;
        }
    }
    
    // Function to traverse the bottom boundary (the leaves).
    // This is a normal dfs but add to ans when node is a leaf.
    void add_leaves(Node* root, vector <int> &ans)
    {
        if(!root) // Empty.
            return;
        if(!root->left && !root->right) // If node is the a leave add to answer and return.
        {
            ans.push_back(root->data);
            return;
        }
        add_leaves(root->left, ans);
        add_leaves(root->right, ans);
    }
    
    // Function ti traverse the right boundary.
    void right_boundary_traversal(Node* curr, vector <int> &ans)
    {
        // We cant get the right boundary in ACW order so we need to store it from root to leaf and reverse it finally.
        vector <int> right; // Vector to store right boundary from root to leaf order.
        while(curr)
        {
            if(curr->left || curr->right) // Push to ans only if current node is not a leaf.
                right.push_back(curr->data);
            if(curr->right) // if a path to right is there go that way.
                curr = curr->right;
            else // go left if right path is not there.
                curr = curr->left;
        }
        // Finally append the right boundary order to ans in reverse order.
        ans.insert(ans.end(), right.rbegin(), right.rend());
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector <int> ans;
        if(!root) // Empty
            return ans;
        if(root->left || root->right) // Add root to ans only if its not a leaf.
        // If root is a leat then it will get handled by add_leaves function.
            ans.push_back(root->data);
        left_boundary_traversal(root->left, ans);
        add_leaves(root, ans);
        right_boundary_traversal(root->right, ans);
        return ans;
    }
};