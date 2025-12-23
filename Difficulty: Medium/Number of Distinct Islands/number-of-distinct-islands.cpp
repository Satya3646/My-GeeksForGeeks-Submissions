// User function Template for C++
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    void bfs(int r, int c, int n, int m, vector <vector <int>> &grid, vector <vector <bool>> &visited, set <vector <pair <int, int>>> &islands)
    {
        
        
        queue <pair <int, int>> q;
        vector <pair <int, int>> curr; // to store the relative indices of the coordinates of the island((r, c) will be considered the origin).
        q.push({r, c});
        visited[r][c] = true;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            curr.push_back({x-r, y-c}); // push the relative index.
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && grid[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        // since we use the starting location (r, c) as the origin similar looking graphs will give similar set of relative coordinates only.
        // We start BFS traversal using a nested loop so the starting point will always be the topmost and leftmost location of the island hence similar island will give same set of relative coordinates.
        sort(curr.begin(), curr.end()); // sort to maintain universal order of relative indices.
        islands.insert(curr);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        set <vector <pair <int, int>>> islands; // store unique islands.
        vector <vector <bool>> visited(n, vector <bool> (m, false));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visited[i][j] && grid[i][j])
                    bfs(i, j, n, m, grid, visited, islands);

        // finally the set will only contain the unique island hence return its size.
        return islands.size();
    }
};
