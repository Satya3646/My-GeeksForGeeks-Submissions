class Solution {
  public:
    void dfs(int r, int c, int n, int  m, vector <vector <char>> &grid)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 'W')
            return;
        grid[r][c] = 'W';
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                if(i != 0 || j != 0)
                    dfs(r+i, c+j, n, m, grid);
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'L')
                {
                    islands++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return islands;
    }
};