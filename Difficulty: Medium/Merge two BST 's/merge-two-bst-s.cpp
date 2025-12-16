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

class BSTIterator {
    stack <Node*> stk; // Imitate the recursion stack.
public:
    BSTIterator(Node* root) {
        Node* curr = root;
        while(curr) // Go deep left pushing the nodes in the way.
            stk.push(curr),
            curr = curr->left;
    }
    
    int next() {
        Node* node = stk.top(); // Extract the top node.
        stk.pop();
        // If the extracted node has a right subtree then go right then go deep left.
        Node* curr = node->right;
        while(curr)
            stk.push(curr),
            curr = curr->left;
        return node->data;
    }

    int peek() {
        return stk.top()->data;
    }
    
    bool hasNext() {
        return !stk.empty();// If the stack is not empty that means there are nodes to be explored.
    }
};

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector <int> merged;
        BSTIterator tree1 = BSTIterator(root1);
        BSTIterator tree2 = BSTIterator(root2);
        while(tree1.hasNext() && tree2.hasNext())
        {
            if(tree1.peek() <= tree2.peek())
                merged.push_back(tree1.next());
            else
                merged.push_back(tree2.next());
        }
        while(tree1.hasNext())
            merged.push_back(tree1.next());
        while(tree2.hasNext())
            merged.push_back(tree2.next());
        return merged;
    }
};