/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, int x, int y, map <int, map<int, vector <int>>> &mp)
    {
        if(!root)
            return;
        mp[x][y].push_back(root->data); // Insert the node into the mapping.
        dfs(root->left, x-1, y+1, mp); // Left --> -1, +1
        dfs(root->right, x+1, y+1, mp); // Right --> +1, +1
    }

    vector <vector <int>> verticalOrder(Node* root)
    {
        vector <vector <int>> ans;
        if(!root) 
            return ans;
        // We need mapping from (x, y) pair to set of nodes sorted in order.
        map <int, map<int, vector <int>>> mp;
        /*
        x defines the column, y defines tree depth of the node.
        We first need to group the nodes based on their x values.
        Then based in their y values since if two nodes have same a and y values then we 
        need to sort them based on values.
        */
        dfs(root, 0, 0, mp);
        for(auto &i : mp) // Iterate over the nodes grouped based on x values.
        {
            vector <int> tmp; // Store the nodes with same x value.
            for(auto &j : i.second) // Iterate over the node grouped (in order) with y values
                tmp.insert(tmp.end(), j.second.begin(), j.second.end()); // Insert the sorted range into the vector.
            ans.push_back(move(tmp)); // Move the group with same x value into the answer.
        }
        return ans;
    }
};