// User function Template for C++
int t = 1;

class Solution {
  public:
    void dfs(int node, int parent, vector <int> adj[], vector <int> &vis, vector <int> &low, vector <int> &tin, set <int> &ans)
    {
        vis[node] = 1;
        low[node] = tin[node] = t++;
        
        int child  = 0;
        for(int i : adj[node])
        {
            if(!vis[i])
            {
                dfs(i, node, adj, vis, low, tin, ans);
                low[node] = min(low[i], low[node]);
                
                if(low[i] >= tin[node] && parent != -1)
                    ans.insert(node);
                    
                child++;
            }
            else if(i != parent)
                low[node] = min(tin[i], low[node]);
        }
        
        if (parent == -1 && child > 1)
            ans.insert(node);
    }
    
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        set <int> ans;
        vector <int> vis(V, 0), low(V), tin(V);
        dfs(0, -1, adj, vis, low, tin, ans);
        return ans.empty()? vector <int> {-1}: vector <int> (ans.begin(), ans.end());
    }
};