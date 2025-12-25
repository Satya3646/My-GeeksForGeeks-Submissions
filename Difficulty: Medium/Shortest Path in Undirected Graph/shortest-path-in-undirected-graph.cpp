class Solution {
  public:
    vector<int> shortestPath(int n, vector<vector<int>> &edges, int src) {
        // code here
        vector <vector <int>> adj(n);
        for(vector <int> &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector <int> ans(n, -1);
        queue <int> q;
        q.push(src);
        ans[src] = 0;
        int dist = 0;
        
        while(!q.empty())
        {
            dist++;
            int qs = q.size();
            while(qs--)
            {
                int node = q.front();
                q.pop();
                for(int i : adj[node])
                {
                    if(i != src && ans[i] == -1)
                    {   
                        ans[i] = dist;
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};
