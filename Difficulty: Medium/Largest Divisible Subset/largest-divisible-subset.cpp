class Solution {
  public:
    vector <int> largestSubset(vector <int> &nums)
    {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        vector <int> dp(n, 1);
        vector <int> par(n, 0);
        int maxLen = 0, indx = -1;
        for(int i = 0; i < n; i++)
        {
            par[i] = i;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = 1 + dp[j];
                    par[i] = j;
                }
            }

            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
                indx = i;
            }
        }

        vector <int> ans;
        while(par[indx] != indx)
        {
            ans.push_back(nums[indx]);
            indx = par[indx];
        }
        ans.push_back(nums[indx]);

        return ans;
    }
};