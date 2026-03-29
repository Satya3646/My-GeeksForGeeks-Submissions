class Solution {
  public:
    int maxChocolate(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        
        // dp[i][j][k] where i = row, j = alice position, k = bob position.
        // Initially alice is at 0,0 and bob is at 0,r-1, hence we update dp[0][0][r-1] = sum of their chocolates.
        vector <vector <vector <int>>> dp(r, vector <vector <int>> (c, vector <int> (c, INT_MIN)));
        dp[0][0][c-1] = grid[0][0] + grid[0][c-1];
        // We can guarante that alice and bob will be on the same row at any given time hence we have same row index i for both of them.
    
        for(int i = 1; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                for(int k = 0; k < c; k++)
                {
                    // if both alice and bob are in the same cell the we can pick the chocolates only once.
                    int val = j == k? grid[i][j]: grid[i][j] + grid[i][k];
                    
                    // prev states which can lead to current state.
                    for(int nj = j-1; nj <= j+1; nj++)
                    {
                        for(int nk = k-1; nk <= k+1; nk++)
                        {
                            if(0 <= nj && nj < c && 0 <= nk && nk < c) // check validity.
                            {
                                dp[i][j][k] = max(dp[i][j][k], val + dp[i-1][nj][nk]);
                            }
                        }
                    }
                }
            }
        }
    
        int ans = INT_MIN;
        for(int i = 0; i < c; i++)
            for(int j = 0; j < c; j++)
                ans = max(ans, dp[r-1][i][j]);
        return ans;
    }
};