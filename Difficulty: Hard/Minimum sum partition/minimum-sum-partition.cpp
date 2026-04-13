class Solution {
  public:
    int minDifference(vector<int>& arr)
    {
        // code here
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
    	int target = total >> 1;
    
    	vector <vector <bool>> dp(n, vector <bool> (target + 1, false));
    
    	for(int i = 0; i < n; i++)
    		dp[i][0] = true;
    
    	if(arr[0] <= target)
    		dp[0][arr[0]] = true;
    
    	for(int i = 1; i < n; i++)
    	{
    		for(int k = 1; k <= target; k++)
    		{
    			int notpick = dp[i-1][k];
    			int pick = false;
    			if(arr[i] <= k)
    				pick = dp[i-1][k - arr[i]];
    			dp[i][k] = pick || notpick;
    		}
    	}
    
    	// dp[i][k] = true if using elements from 0 to i, a substet with sum k can be formed or not.
    	int minDiff = INT_MAX;
    	for(int k = target; k >= 0; k--)
    	{
    		if(dp[n-1][k])
    			minDiff = min(minDiff, (total - 2*k));
    	}
    
    	return minDiff;
    }
};
