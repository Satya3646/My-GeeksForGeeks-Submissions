class Solution {
  public:
    int solve(int i, int j, vector <int> &arr, vector <vector <int>> &dp)
    {
        if(i == j)
            return 0;
    
        if(dp[i][j] != -1)
            return dp[i][j];
    
        int minCost = INT_MAX;
    
        for(int k = i; k < j; k++)
        {
            int cost = solve(i, k, arr, dp) + solve(k+1, j, arr, dp) + arr[i-1] * arr[k] * arr[j];
            minCost = min(minCost, cost);
        }
    
        return dp[i][j] = minCost;
    }
    
    int matrixMultiplication(vector <int> &arr)
    {
        int n = arr.size()-1;
        vector <vector <int>> dp(n+1, vector <int> (n+1, -1));
        solve(1, n, arr, dp);
        return dp[1][n] == -1? 0: dp[1][n];
    }
};