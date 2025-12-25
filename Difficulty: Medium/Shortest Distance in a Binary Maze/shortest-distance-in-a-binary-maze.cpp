// User function Template for C++
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    int shortestPath(vector <vector <int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>> ans(m, vector <int> (n, -1));
        queue <pair <int, int>> q;
        if(grid[source.first][source.second]) // push only if starting node is a '0'.
        { 
            q.push(source);
            ans[source.first][source.second] = 0;
        }
        int dist = 0; // since we need the count of 0's in path and not the edges.
    
        while(!q.empty())
        {
            int qs = q.size();
            dist++;
            while(qs--)
            {
                auto [x, y] = q.front();
                q.pop();
                // check the neighbors.
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    // if neighbor is a 1 and not visited yet the push to queue.
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] && ans[nx][ny] == -1)
                    {
                        ans[nx][ny] = dist;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans[destination.first][destination.second]; // it will remain as -1 if it was not reachable else shorterst distance will be returned.
    }
};
