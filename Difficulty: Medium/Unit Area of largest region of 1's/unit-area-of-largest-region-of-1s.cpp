class dsu{
public:
    vector <int> parent, size;
    int maxIsland;
    
    dsu(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
        maxIsland = 0;
    }
    
    int findPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void Union(int u, int v)
    {
        int ulpu = findPar(u);
        int ulpv = findPar(v);
        
        if(ulpu == ulpv)
            return;
        
        if(size[ulpu] < size[ulpv])
            swap(ulpu, ulpv);
            
        parent[ulpv] = ulpu;
        size[ulpu] += size[ulpv];
        maxIsland = max(maxIsland, size[ulpu]);
    }
};

const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

class Solution {
public:
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dsu islands = dsu(n*m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]) // if current cell is land.
                {  
                    // check and merge with neighboring land.
                    for(int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        // if neighbor is a land cell and not connected to current 
                        // land cell the connect them.
                        if(0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] && 
                           islands.findPar(m*nx + ny) != islands.findPar(m*i + j))
                            islands.Union(m*i + j, m*nx + ny);
                    }
                    islands.maxIsland = max(islands.maxIsland, islands.size[m*i + j]);
                }
            }
        }

        return islands.maxIsland;
    }
};