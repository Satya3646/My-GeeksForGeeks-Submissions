/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Encodes a tree to a single string.
    vector <int> serialize(Node* root) {
        vector <int> arr;
        if(!root)
            return {-1};
        // We will serialize the tree is BFS order, accounting for the null nodes in between.
        // This way we will get the string is level by level order.
        queue <Node*> q; // BFS queue.
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node == nullptr)
                {
                    arr.push_back(-1);
                    continue;
                }
                arr.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }
        return arr;
    }

    // Decodes your encoded data to tree.
    Node* deSerialize(vector <int> &arr) {
        queue <Node*> q;
        if(arr[0] == -1)
            return nullptr;
        Node* root = new Node(arr[0]);
        q.push(root);
        int indx = 1;
        while(!q.empty())
        {
            Node* parent = q.front();
            q.pop();
            if(arr[indx] != -1) // if stream has not ended and the extracted value is not null the add it to the tree and queue.
            {    
                parent->left = new Node(arr[indx]);
                q.push(parent->left);
            }
            indx++;
            if(arr[indx] != -1)
            {
                parent->right = new Node(arr[indx]);
                q.push(parent->right);
            }
            indx++;
        }
        return root;
    }
};