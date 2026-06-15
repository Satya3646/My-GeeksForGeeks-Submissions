// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector <string> &arr)
    {
        int n = arr.size();
        int j = 0;
        string ans = "";
        while(true)
        {
            for(int i = 0; i < n; i++)
            {
                if(j == arr[i].size())
                    return ans;
                if(arr[i][j] != arr[0][j])
                    return ans;
            }
            ans += arr[0][j];
            j++;
        }
    }
};