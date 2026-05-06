// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        vector <int> dp(n+1, 0);
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], dp[i-j] + price[j-1]);
            }
        }
        
        return dp[n];
    }
};