/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector <int> ans;
        if(!root)
            return ans;
        map <int, int> mp;
        queue <pair <Node*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front().first;
                int x = q.front().second;
                q.pop();
                mp[x] = node->data;
                if(node->left)
                    q.push({node->left, x-1});
                if(node->right)
                    q.push({node->right, x+1});
            }
        }
        for(auto &p : mp)
            ans.push_back(p.second);
        return ans;
    }
};