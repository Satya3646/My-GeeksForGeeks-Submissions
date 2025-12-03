// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        stack <Node*> stk; // Stack to mimic call stack
        vector <int> ans;
        if(!root) // if tree is empty return empty answer
            return ans;
        Node* curr = root; // Iterator
        while(curr || !stk.empty())
        {
            while(curr) // Go deep left
            {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); // Pop the last left node seen
            stk.pop();
            ans.push_back(curr->data); // Add its value to the answer
            curr = curr->right; // Go right of the popped node  
        }
        return ans;
    }
};