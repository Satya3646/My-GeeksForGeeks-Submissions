/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector <int> ans;
        queue <Node*> q; // q for BFS traversal.
        if(root) // Only start bfs if tree is not empty.
            q.push(root);
        bool f = false; // flag to filp the order for odd levels (true), even levels (false).
        while(!q.empty())
        {
            int n = q.size();
            vector <int> tmp(n);
            for(int i = 0; i < n; i++)
            {
                int indx = f? n-i-1: i; // if f is true then it is odd level so index needs to be flipped hence do n-i-1 else even level so take i directly.
                Node* node = q.front();
                q.pop();
                tmp[indx] = node->data;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.insert(ans.end(),tmp.begin(), tmp.end());
            f = !f; // Filp the flag for next level.
        }
        return ans;
    }
};