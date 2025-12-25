class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector <vector <pair <int, int>>> adj(V);
        for(vector <int> &v : edges) // bidirectional weighted edge.
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        vector <int> dist(V, INT_MAX); // distance initially empty.
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq; // min-heap.
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            auto [d, node] = pq.top(); // extract the top node.
            pq.pop();
            
            if(dist[node] < d) // if popped distance is greater than the distance stored, node is already processed and has the minimum distance stored so skip.
                continue;
            
            for(auto &[i, wt] : adj[node]) // neighbors.
            {
                if(dist[i] > d + wt) // if stored distance is larger than path through the parent node the update its distance and push to queue.
                {
                    dist[i] = d + wt;
                    pq.push({dist[i], i});
                }
            }
        }
        
        for(int &i : dist) // the unreachable nodes remain at infinity mark them with -1.
            if(i == INT_MAX)
                i = -1;
        
        return dist;
    }
};