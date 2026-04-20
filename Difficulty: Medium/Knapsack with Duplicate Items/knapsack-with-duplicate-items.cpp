class Solution {
  public:
    int knapSack(vector <int> &val, vector <int> &wt, int capacity)
    {
        int n = val.size();
        vector <int> dp(capacity+1);
        
        for(int j = 1; j <= capacity; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(wt[i] <= j)
                    dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }
        
        return dp[capacity];
    }
};