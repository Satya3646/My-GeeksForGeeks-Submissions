class Solution {
  public:
    void NSE(vector <int> &arr, vector <int> &nse)
    {
        int n = arr.size();
        stack <int> stk;
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            
            if(!stk.empty())
                nse[i] = stk.top();
            
            stk.push(i);
        }
    }
    
    void PSE(vector <int> &arr, vector <int> &pse)
    {
        int n = arr.size();
        stack <int> stk;
        
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            
            if(!stk.empty())
                pse[i] = stk.top();
            
            stk.push(i);
        }
    }
    
    int largestRectangleInHistogram(vector <int> &arr)
    {
        int n = arr.size();
        vector <int> nse(n, n), pse(n, -1);
        NSE(arr, nse);
        PSE(arr, pse);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, arr[i] * (nse[i] - pse[i] - 1));
        
        return ans;
    }
    
    int maxArea(vector <vector <int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        int ans = largestRectangleInHistogram(mat[0]);
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                    mat[i][j] += mat[i-1][j];
            }
            ans = max(ans, largestRectangleInHistogram(mat[i]));
        }
        
        return ans;
    }
};