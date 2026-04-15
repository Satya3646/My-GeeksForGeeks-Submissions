class Solution {
  public:
    int findMin(int n) {
        // code here
        vector <int> denominations = {10, 5, 2, 1};
        int j = 0;
        int cnt = 0;
        while(n && j < 4)
        {
            while(n >= denominations[j])
            {
                cnt++;
                n -= denominations[j];
            }
            j++;
        }
        return cnt;
    }
};