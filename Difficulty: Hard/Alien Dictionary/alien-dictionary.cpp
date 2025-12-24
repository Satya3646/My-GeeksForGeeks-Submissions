    class Solution {
      public:
        string findOrder(vector<string> &words) {
            // code here
            int n = words.size();
            vector <vector <int>> adj(26); // adjacency matrix for whole english alphabet, we will only use those slots in out words.
            vector <int> indegree(26, -1); // indegree also acting as a flag indicating if al character is part of the graph or not.
            for(string &s : words)
                for(char c : s) // only the characters present in dictionary can have indegree = 0, non-existant characters will have indegree = -1.
                    indegree[c-'a'] = 0;
    
            for(int i = 1; i < n; i++) // create edges between consecutive words.
            {
                string s1 = words[i-1]; // u.
                string s2 = words[i]; // v.
                int len = min(s1.size(), s2.size());
                bool noEdge = true; // true if no edge exists.
                for(int j = 0; j < len; j++)
                {
                    if(s1[j] != s2[j]) // find first different charater, create edge and break.
                    {
                        indegree[s2[j]-'a']++;
                        adj[s1[j]-'a'].push_back(s2[j]-'a');
                        noEdge = false; // edge is present so set it to false.
                        break;
                    }
                }
                if(noEdge && s1.size() > s2.size()) // if no edge is present and s1 is larger that s2 that means the given dictionary is wrong (inconsistent).
                // triggers at invalid input, lexicographical order broken as s2 is a prefix of s1 which cannot be the case if the dictionary is in lexicographical order..
                    return "";
            }
            
            queue <int> q;
            string alphabet = "";
            int letterCnt = 26; // count of letter present in current dictionary.
            for(int i = 0; i < 26; i++)
            {
                if(!indegree[i])
                    q.push(i);
                else if(indegree[i] == -1)
                    letterCnt--;
            }
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                alphabet += char('a' + node);
                for(int i : adj[node])
                {
                    if(!--indegree[i])
                        q.push(i);
                }
            }
            
            if(alphabet.size() != letterCnt) // if all letters are not added to alphabet the a cycle exist hence return empty string.
                return "";
            return alphabet;
        }
    };