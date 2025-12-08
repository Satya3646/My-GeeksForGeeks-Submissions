/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, vector <int> &currPath, vector <vector <int>> &paths)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            currPath.push_back(root->data);
            paths.push_back(currPath);
            currPath.pop_back();
            return;
        }
        currPath.push_back(root->data);
        dfs(root->left, currPath, paths);
        dfs(root->right, currPath, paths);
        currPath.pop_back();
    }
    
    vector <vector <int>> Paths(Node* root)
    {
        // code here
        vector <vector <int>> paths;
        if(!root)
            return paths;
        vector <int> tmp;
        dfs(root, tmp, paths);
        return paths;
    }
};