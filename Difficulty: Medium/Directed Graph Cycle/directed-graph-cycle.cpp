class Solution {
  public:
    bool dfs(int node, vector <vector <int>> &adj, vector <bool> &visited, vector <bool> &pathVis)
    {
    	// marks as visited.
    	visited[node] = true; 
    	pathVis[node] = true;
    
    	for(int i : adj[node]) // adjacents.
    	{
    		if(!visited[i] && dfs(i, adj, visited, pathVis)) // not visited and dfs returns true then return true.
    			return true;
    		else if(pathVis[i]) // current node is already visited and alos part of the current path --> cycle.
    			return true;
    	}
    	pathVis[node] = false; // restore pathVis before backtracking.
    	return false;
    }
    
    bool isCyclic(int n, vector<vector<int>>& edges)
    {
    	// Write your code here
    	vector <vector <int>> adj(n);
    	for(vector <int> &v : edges)
    		adj[v[0]].push_back(v[1]);
    	vector <bool> visited(n, false); // global visited array to capture components.
    	vector <bool> pathVis(n, false); // visited array to keep track of nodes visited only on the current path.
    
    	for(int i = 0; i < n; i++)
    		if(!visited[i] && dfs(i, adj, visited, pathVis))
    			return true;
    	return false;
    }
};