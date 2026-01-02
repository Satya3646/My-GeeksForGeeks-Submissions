// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        // Code here
        vector <int> dist(n, 1e8);
        dist[src] = 0;
    
        for(int i = 1; i < n; i++)
            for(vector <int> &v : edges)
                if(dist[v[0]] != 1e8 && dist[v[1]] > dist[v[0]] + v[2])
                    dist[v[1]] = dist[v[0]] + v[2];
                    
        for(vector <int> &v : edges)
            if(dist[v[0]] != 1e8 && dist[v[1]] > dist[v[0]] + v[2])
                return {-1};
                
        return dist;
    }
};
