// User function template for C++
const int inf = 1e8;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int k = 0; k < n; k++) // selects an intemediate node k.
        {
            for(int i = 0; i < n; i++) // select start location.
            {
                for(int j = 0; j < n; j++) // select target location.
                {
                    if(dist[i][k] == inf || dist[k][j] == inf) // if k is not reachable from i or j cant be reached from k the skip.
                        continue;
                    // update the minimum distance.
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};