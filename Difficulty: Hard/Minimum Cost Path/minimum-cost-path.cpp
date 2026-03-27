const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector <int>> dist(m, vector <int> (n, INT_MAX));
        dist[0][0] = grid[0][0];
        
        priority_queue <pair <int, pair <int, int>>,
                        vector <pair <int, pair <int, int>>>,
                        greater <pair <int, pair <int, int>>>> pq;
        pq.push({dist[0][0], {0, 0}});
        
        while(!pq.empty())
        {
            auto [d, cell] = pq.top();
            auto [x, y] = cell;
            pq.pop();
            
            if(dist[x][y] < d)
                continue;
                
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < m && 0 <= ny && ny < n)
                {
                    if(d + grid[nx][ny] < dist[nx][ny])
                    {
                        dist[nx][ny] = d + grid[nx][ny];
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};