/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node *root, int &sum)
    {
        if(!root) // Base Case
            return 0;
        int lsum = max(0, solve(root->left, sum)); // Take lsum if its +ve else prune it i.e. lsum = 0;
        int rsum = max(0, solve(root->right, sum)); // Take rsum if its +ve else prune it i.e. rsum = 0;
        sum = max(sum, lsum + rsum + root->data); // Now compare the path sum i.e. considering that left, right and root as a complete path get the sum and update the global value.
        return root->data + max(lsum, rsum); // We need to return the best sum resulting from the root and one of its subtree since the return value is part of the path we want to make and not a complete one.
    }

    int findMaxSum(Node* root) {
        int sum = INT_MIN; // Initialize sum to INTMIN since -ve values are also there in the tree
        solve(root, sum); // Call function to update the sum
        return sum;
    }
};