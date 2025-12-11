// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        // Inorder : left --> root --> right.
        // BST : left = smaller than root, right = greater than root.
        // --> Inorder = sorted order of the values.
        int n = arr.size();
        for(int i = 1; i < n; i++)
            if(arr[i] <= arr[i-1])
                return false;
        return true;
    }
};