const int mod = 1e9+7;

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector <vector <pair <int, int>>> adj(n); // node --> (neighbors, weights).
        for(vector <int> &v : roads)
        {
            // undirected edges.
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        vector <long long> dist(n, LLONG_MAX); // stores shortest distance to a node.
        vector <long long> ways(n, 0); // stores number of ways to reach a node.
        priority_queue <pair <long long, int>, 
                        vector <pair <long long, int>>,
                        greater <pair <long long, int>>> pq; // keeps the shortest distance node at the top.
        dist[0] = 0;
        pq.push({0, 0});
        ways[0] = 1; // wats to reach node 0 = 1.

        while(!pq.empty())
        {
            auto [d, node] = pq.top(); // extract the node and its distance.
            pq.pop();

            if(dist[node] < d) // if shortest distance is smaller it is a stale entry so skip.
                continue;

            for(auto &[i, wt] : adj[node]) // neighbors. 
            {
                if(dist[i] > d + wt) // if path through parent node is shorter.
                {
                    dist[i] = d + wt; // update with min value.
                    pq.push({dist[i], i});
                    ways[i] = ways[node]; // number of ways to reach current node is same as the number of ways to reach the parent node.
                }
                else if(dist[i] == d + wt) // if path through the parent to current node has the same distance as the minimum distance to reach the current node.
                    // the node can reach as directly to the current node or choose path through the parent hence we add them up.
                    ways[i] = (ways[i] + ways[node]) % mod;
            }
        }

        return ways[n-1] % mod;
    }
};