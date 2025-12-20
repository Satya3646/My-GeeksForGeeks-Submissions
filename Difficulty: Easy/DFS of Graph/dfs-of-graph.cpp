class Solution {
  public:
    void getDFS(int node, const vector <vector <int>> &adj, vector <bool> &visited, vector <int> &traversal)
    {
        if(node == adj.size())  
            return;
        traversal.push_back(node);
        for(int i : adj[node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                getDFS(i, adj, visited, traversal);
            }
        }
    }
    
    vector<int> dfs(vector <vector <int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector <int> traversal;
        vector <bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                getDFS(i, adj, visited, traversal);
            }
        }
        return traversal;
    }
};