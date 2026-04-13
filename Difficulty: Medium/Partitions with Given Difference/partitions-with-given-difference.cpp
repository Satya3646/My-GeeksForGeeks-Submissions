const int mod = 1e9+7;

class Solution {
  public:
    int countPartitions(vector <int> &arr, int diff)
    {
        // Code here
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector <int> dp(total + 1, 0);
    
        // i = 0 case, pick & notpick.
        dp[0] = 1;
        if(arr[0] <= total)
            dp[arr[0]] += 1;
    
        for(int i = 1; i < n; i++)
            for(int k = total; k >= arr[i]; k--)
                dp[k] = (dp[k] + dp[k - arr[i]]) % mod;
    
        // diff = total - 2k ==> k = (total - diff) / 2, number of ways to form k is the answer.
        for(int k = 0; k <= total; k++)
            if(total - 2*k == diff)
                return dp[k];
        
        return 0;
    }
};