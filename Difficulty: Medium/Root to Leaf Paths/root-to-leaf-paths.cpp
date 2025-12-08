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
        currPath.push_back(root->data); // Add the current node to the path.
        if(!root->left && !root->right) // If the node is a leaf then add the total path to paths.
            paths.push_back(currPath);
        else // else traverse deeper into the tree.
        {
            dfs(root->left, currPath, paths);
            dfs(root->right, currPath, paths);
        }
        currPath.pop_back(); // Pop the pushed element to backtrack.
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