// User function Template for C++

class Solution {
  public:
    int maximumPath(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
            
        vector <vector <int>> dp(n, vector <int> (m, INT_MIN));
        dp[0] = matrix[0]; // first row is the starting point.
    
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // reach current cell from top cell.
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
    
                // left diagonally above cell.
                if(j > 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
    
                // right diagonally above cell.
                if(j < m-1)
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
    
                dp[i][j] += matrix[i][j];
            }
        }
    
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};