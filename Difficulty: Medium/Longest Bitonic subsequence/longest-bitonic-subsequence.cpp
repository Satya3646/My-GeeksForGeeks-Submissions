class Solution {
  public:
    int longestBitonicSequence(int n, vector <int> &arr) {
        // code here
        vector <int> LIS(n, 1), LDS(n, 1);
    	int ans = 0;
    	for(int i = 1; i < n; i++)
    	{
    		for(int j = 0; j < i; j++)
    		{
    			if(arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
    				LIS[i] = LIS[j] + 1;
    		}
    	}
    
    	for(int i = n-2; i >= 0; i--)
    	{
    		for(int j = i+1; j < n; j++)
    		{
    			if(arr[i] > arr[j] && LDS[i] < LDS[j] + 1)
    				LDS[i] = LDS[j] + 1;
    		}
    	}
    
    	for(int i = 0; i < n; i++)
    	    if(LIS[i] > 1 && LDS[i] > 1)
    		    ans = max(ans, LIS[i] + LDS[i] - 1);
    	return ans;
    }
};
