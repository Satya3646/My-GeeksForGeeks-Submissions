class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges)
    {
        // Visiting all the nodes through shortest edges till all nodes are visited will give the MST edges.
        vector <vector <pair <int, int>>> adj(n);
        for(vector <int> &v : edges)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        vector <bool> visited(n, false);
        int sum = 0;
        priority_queue <pair <int, int>,
                        vector <pair <int, int>>, 
                        greater <pair <int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            if(visited[node])
                continue;
            sum += d;
            visited[node] = true;
            for(auto &[i, wt] : adj[node])
            {
                if(!visited[i])
                    pq.push({wt, i});
            }
        }
        return sum;
    }
};