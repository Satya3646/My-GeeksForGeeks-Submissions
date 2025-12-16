// User function Template for C++

class Solution {
  public:
    void check(int &indx, int arr[], int n, int low, int high)
    {
        if(indx >= n || arr[indx] < low || arr[indx] > high)
            return;
        int root = arr[indx++];
        check(indx, arr, n, low, root);
        check(indx, arr, n, root, high);
    }
    
    int canRepresentBST(int arr[], int n)
    {
        // code here
        int indx = 0;
        check(indx, arr, n, INT_MIN, INT_MAX);
        return indx == n;
    }
};