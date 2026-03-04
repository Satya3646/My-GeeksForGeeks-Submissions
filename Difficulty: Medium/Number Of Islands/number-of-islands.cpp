class dsu{
    public:
        vector <int> parent, size;
        
        dsu(int n)
        {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n, 1);
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
        }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector <vector<int>> &operators)
    {
        int k = operators.size();
        
        vector <int> ans;
        vector <vector <bool>> matrix(n, vector <bool> (m, false));
        
        int cnt = 0;
        dsu islands = dsu(n*m);
        for(int i = 0; i < k; i++)
        {
            int x = operators[i][0];
            int y = operators[i][1];
            
            if(!matrix[x][y])
            {
                cnt++;
                matrix[x][y] = true;
                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(0 <= nx && nx < n && 
                       0 <= ny && ny < m &&
                       matrix[nx][ny] &&
                       islands.findPar(m*x + y) != islands.findPar(m*nx + ny))
                    {
                        cnt--;
                        islands.Union(m*x + y, m*nx + ny);
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
