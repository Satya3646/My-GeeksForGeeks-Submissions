// User function Template for C++
const int mod = 1e9+7;

class Solution {
  public:
    long long help(int n, vector <long long> &dp)
    {
        if(n <= 1)
            return n;
            
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = (help(n-1, dp) + help(n-2, dp)) % mod;
    }
    
    long long int topDown(int n)
    {
        if(n <= 1)
            return n;
            
        vector <long long> dp(n+1, -1);
        help(n, dp);
        
        return dp[n];
    }

    long long int bottomUp(int n)
    {
        vector <long long> fib(n+1, 0);
        fib[1] = 1;
    
        for(int i = 2; i <= n; i++)
            fib[i] = (fib[i-1] + fib[i-2]) % mod;
        
        return fib[n];
    }
};