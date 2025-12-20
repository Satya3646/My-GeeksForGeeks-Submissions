class Solution {
  public:
    bool dfs(int node, int parent, vector <vector <int>> &adj, vector <bool> &visited)
    {
        visited[node] = true; // mark the current node as visited.
        
        for(int i : adj[node]) // iterate the adjacent nodes.
        {
            if(!visited[i]) // if not visited the traverse it.
            {
                if(dfs(i, node, adj, visited))
                    return true;
            }
            else if(i != parent) // if the adjacent node is already marked as visited but is not the parent node then return true since this is possible only when there is a cycle in the graph
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Create adjacency list.
        vector <vector <int>> adj(V);
        for(vector <int> &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector <bool> visited(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};