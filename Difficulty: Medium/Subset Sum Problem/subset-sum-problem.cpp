class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector <vector <bool>> dp(n, vector <bool> (sum + 1, false));
        
        if(arr[0] <= sum) 
            dp[0][arr[0]] = true;
        
        // target sum of 0 is always achievable by picking no elements.
        for(int i = 0; i < n; i++)
            dp[i][0] = true;
            
        for(int i = 1; i < n; i++)
        {
            for(int k = 1; k <= sum; k++)
            {
                // current element is not picked so, if target k can be formed before current index then set true.
                bool notPick = dp[i-1][k];
                
                // if we pick current element, the we can form target k if k-current can be formed before current index.
                bool pick = false;
                if(arr[i] <= k)
                    pick = dp[i-1][k - arr[i]];
                
                dp[i][k] = pick || notPick;
            }
        }
        
        return dp[n-1][sum];
    }
};