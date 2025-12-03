/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void preOrder(Node *root, vector <int> &ans)
    {
        if(root == nullptr)
            return;
        ans.push_back(root->data);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    
    vector<int> preOrder(Node* root) {
        // code here
        vector <int> order;
        preOrder(root, order);
        return order;
    }
};