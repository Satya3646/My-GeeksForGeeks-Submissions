class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector <vector <pair <int, int>>> adj(V);
        for(vector <int> &v : edges)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        vector <int> dist(V, INT_MAX);
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            
            if(dist[node] < d)
                continue;
            
            for(auto &[i, wt] : adj[node]) 
            {
                if(dist[i] > d + wt)
                {
                    dist[i] = d + wt;
                    pq.push({dist[i], i});
                }
            }
        }
        
        for(int &i : dist)
            if(i == INT_MAX)
                i = -1;
        
        return dist;
    }
};