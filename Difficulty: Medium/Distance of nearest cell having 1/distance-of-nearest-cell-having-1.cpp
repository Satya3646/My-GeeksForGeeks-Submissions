const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    vector <vector <int>> nearest(vector <vector <int>> &mat)
    {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector <vector <int>> nearestZero(m, vector <int> (n, 0));
    vector <vector <bool>> visited(m, vector <bool> (n, false));
    queue <pair <int, int>> q;

    // Push all the ones into the BFS queue so that only zeros remain unvisited.
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++) 
        { 
            if(mat[i][j] == 1)
            {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while(!q.empty())
    {
        int qs = q.size();
        for(int i = 0; i < qs; i++)
        {
            // Unpack the coordinates from the front of the queue.
            auto [x, y] = q.front();
            q.pop();
            for(int j = 0; j < 4; j++) // iterate the adjacent nodes.
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                // if a node is unvisited then it is definitely a zero since we added all the onse beforehand.
                if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    nearestZero[nx][ny] = 1 + nearestZero[x][y]; // current node is +1 distance from its parent (the previous level).
                    q.push({nx, ny});
                }
            }
        }
    }
    return nearestZero;
    }
};