class Solution {
  public:
    vector<int> safeNodes(int n, vector<vector<int>>& graph) {
        // Code here
        vector <vector <int>> reverseGraph(n); // reversed edges.
        vector <int> indegree(n); // indegree of nodes in reversed graph.
        queue <int> q;
        
        for(vector <int> &edge : graph)
        {
            indegree[edge[0]]++;
            // take edge in graph(those coming out of edge[0] towards edge[1]) and point them from edge[1] towards edge[0].
            reverseGraph[edge[1]].push_back(edge[0]);
        }
    
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
    
        vector <int> safeNodes;
        safeNodes.reserve(n);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int i : reverseGraph[node])
                if(!--indegree[i])
                    q.push(i);
        }
        
        return safeNodes;
    }
};