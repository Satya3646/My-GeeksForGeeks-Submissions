class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // code here
        int n = prices.size();
        if(n <= 1)
            return 0;

        int hold = -prices[0];
        int sell = 0;
        int rest = 0;

        for(int i = 1; i < n; i++)
        {
            hold = max(hold, rest - prices[i]);
            rest = max(rest, sell);
            sell = hold + prices[i];
        }

        return max(rest, sell);
    }
};