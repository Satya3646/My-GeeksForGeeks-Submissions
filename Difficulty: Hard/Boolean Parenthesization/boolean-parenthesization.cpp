// User function Template for C++
const int mod = INT_MAX;

class Solution {
  public:
    int solve(int i, int j, bool isTrue, string &exp, vector <vector <vector <int>>> &dp)
    {
        if(i > j)
            return 0;
    
        if(i == j)
            return ((isTrue && exp[i] == 'T') || (!isTrue && exp[i] == 'F'));
    
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        int ways = 0;
        for(int k = i+1; k <= j-1; k += 2)
        {
            char op = exp[k];
    
            int leftTrue = solve(i, k-1, true, exp, dp);
            int leftFalse = solve(i, k-1, false, exp, dp);
            int rightTrue = solve(k+1, j, true, exp, dp);
            int rightFalse = solve(k+1, j, false, exp, dp);
    
            if(op == '|')
            {
                if(isTrue)
                    ways = (ways + (1LL * leftTrue * rightFalse) % mod + (1LL * leftFalse * rightTrue) % mod + (1LL * leftTrue * rightTrue) % mod) % mod;
                else
                    ways = (ways + (1LL * leftFalse * rightFalse) % mod) % mod;
            }
            else if(op == '&')
            {
                if(isTrue)
                    ways = (ways + (1LL * leftTrue * rightTrue) % mod) % mod;
                else
                    ways = (ways + (1LL * leftTrue * rightFalse) % mod + (1LL * leftFalse * rightTrue) % mod + (1LL * leftFalse * rightFalse) % mod) % mod;
            }
            else if(op == '^')
            {
                if(isTrue)
                    ways = (ways + (1LL * leftTrue * rightFalse) % mod + (1LL * leftFalse * rightTrue) % mod) % mod;
                else
                    ways = (ways + (1LL * leftTrue * rightTrue) % mod + (1LL * leftFalse * rightFalse) % mod) % mod;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(string & exp)
    {
        int n = exp.size();
        vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (2, -1)));
        return solve(0, n-1, true, exp, dp);
    }
};