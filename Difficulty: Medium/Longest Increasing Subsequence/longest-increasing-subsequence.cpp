class Solution {
  public:
    int lis(vector<int>& nums) {
        // code here
        int n = nums.size();

        vector <int> tmp;
        tmp.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            int num = nums[i];
            if(num > tmp.back())
                tmp.push_back(num);
            else
                tmp[(lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin())] = num;
        }

        return tmp.size();
    }
};