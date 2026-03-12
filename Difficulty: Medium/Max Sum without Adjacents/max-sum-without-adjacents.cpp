// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector <int> dp(n);
    
        dp[0] = nums[0];
        if(n == 1)
            return dp[0];
        dp[1] = max(nums[0], nums[1]);
        
            
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    
        return dp[n-1];
    }
};