// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(int i, int j, string &s, vector <int> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(isPalindrome(i, j, s))
            return 0;
        
        int cuts = INT_MAX;
        for(int k = i; k < j; k++)
        {
            if(!isPalindrome(i, k, s))
                continue;
            int curr = 1 + solve(k+1, j, s, dp);
            cuts = min(cuts, curr);
        }

        return dp[i] = cuts;
    }

    int palPartition(string &s)
    {
        int n = s.size();
        vector <int> dp(n, -1);
        return solve(0, n-1, s, dp);
    }
};