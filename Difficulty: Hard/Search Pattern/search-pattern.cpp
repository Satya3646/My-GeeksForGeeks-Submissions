class Solution {
  public:
    void buildLPS(string &pattern, vector <int> &lps)
    {
        int n = pattern.size();
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while(i < n)
        {
            if(pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len > 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    vector<int> search(string &pat, string &txt) {
        // code here
        int m = pat.size();
        int n = txt.size();
        vector <int> lps(m);
        buildLPS(pat, lps);
        
        int i = 0, j = 0;
        vector <int> ans;
        while(i < n)
        {
            if(txt[i] == pat[j])
            {
                i++;
                j++;
            }
            
            if(j == m)
            {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if(i < n && txt[i] != pat[j])
            {
                if(j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        
        return ans;
    }
}; 