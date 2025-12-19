class Solution {
  public:
    vector<int> bfs(vector <vector <int>> &adj) {
        // code here
        int n = adj.size();
        queue <int> q;
        vector <int> list;
        vector <int> visited(n, 0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                int node = q.front();
                q.pop();
                list.push_back(node);
                for(int j : adj[node])
                {
                    if(!visited[j])
                    {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
        return list;
    }
};