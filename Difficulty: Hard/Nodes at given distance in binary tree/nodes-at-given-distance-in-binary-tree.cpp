/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
    void dfs(Node* root, unordered_map <Node*, Node*> &parent)
    {
        if(!root)
            return;
        Node* l = root->left;
        Node* r = root->right;
        if(l)
            parent[l] = root;
        if(r)
            parent[r] = root;
        dfs(l, parent);
        dfs(r, parent);
    }
    
    Node* findNode(Node* root, int target)
    {
        if(!root)
            return nullptr;
        if(root->data == target)
            return root;
        Node* l = findNode(root->left, target);
        Node* r = findNode(root->right, target);
        if(l)
            return l;
        return r;
    }

    vector <int> KDistanceNodes(Node* root, int target, int k)
    {
        unordered_map <Node*, Node*> parent; // Node to parent mapping.
        dfs(root, parent); // Update the map.
        queue <Node*> q; // BFS queue
        unordered_set <Node*> visited; // visited array.
        Node* targetNode = findNode(root, target);
        q.push(targetNode);
        visited.insert(targetNode);
        int dist = 0; // Level indicator.
        while(!q.empty())
        {
            if(dist == k) // If its the kth BFS level then stop traversal since now queue contains all the nodes with distance k from target node.
                break;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end())
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            dist++;
        }
        vector <int> ans;
        while(!q.empty())
            ans.push_back(q.front()->data),
            q.pop();
        sort(ans.begin(), ans.end());
        return ans;
    }
};