/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void bfs(Node* root, int x, map <int, int> &mp)
    {
        queue <pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                pair <Node*, int> p = q.front();
                q.pop();
                if(mp.find(p.second) == mp.end()) // Put into map only if its the first node with that value of x-coordinate
                    mp[p.second] = p.first->data;
                if(p.first->left)
                    q.push({p.first->left, p.second-1});
                if(p.first->right)
                    q.push({p.first->right, p.second+1});
            }
        }
    }
    
    vector <int> topView(Node *root) {
        vector <int> ans;
        if(!root)
            return ans;
        map <int, int> mp; // x-coordinate to node value mapping
        /* 
        Here we need bfs since we need to store the nodes by gradually
        goind down the tree i.e. level order traversal, since we need to 
        store the first node visible as we gradullay increase the y-coordinate
        */
        bfs(root, 0, mp); // Update the map using bfs
        for(auto &p : mp)
            ans.push_back(p.second);
        return ans;
    }
};