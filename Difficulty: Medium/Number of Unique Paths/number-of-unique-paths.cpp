// User function template in C++

class Solution {
  public:
    // Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        // code here
    	vector <vector <int>> dp(m, vector <int> (n, 1));

    	for(int i = 1; i < m; i++)
    		for(int j = 1; j < n; j++)
    			dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    	return dp[m-1][n-1];
    }
};
