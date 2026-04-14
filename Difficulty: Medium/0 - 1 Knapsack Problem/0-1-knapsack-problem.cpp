class Solution {
  public:
    int knapsack(int maxWeight, vector <int> &value, vector<int> &weight)
    {
        // code here
        int n = weight.size();
        vector <int> dp(maxWeight+1, -1);
    	dp[0] = 0;
    	if(weight[0] <= maxWeight)
    		dp[weight[0]] = value[0];
    
    	for(int i = 1; i < n; i++)
    	{
    		for(int wt = maxWeight; wt >= weight[i]; wt--)
    		{
    			int notpick = dp[wt];
    			int pick = INT_MIN;
    			if(dp[wt - weight[i]] != -1)
    				pick = dp[wt - weight[i]] + value[i];
    			dp[wt] = max(pick, notpick);
    		}
    	}
    
    	return *max_element(dp.begin(), dp.end());
    }
};