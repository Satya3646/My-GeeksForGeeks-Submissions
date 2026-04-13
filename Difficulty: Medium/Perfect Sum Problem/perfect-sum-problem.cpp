const int mod = 1e9+7;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int k)
    {
        // code here
        int n = arr.size();
    
        vector <int> dp(k+1, 0);
        dp[0] = 1; // not pick the first element.
    
        if(arr[0] <= k) // pick the first element.
            dp[arr[0]] += 1;
        
        for(int i = 1; i < n; i++)
            for(int sum = k; sum >= arr[i]; sum--)
                dp[sum] = (dp[sum] + dp[sum - arr[i]]) % mod;
    
        return dp[k];
    }
};