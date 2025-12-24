class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector <vector <int>> adj(V);
        vector <int> indegree(V);
        vector <int> topo;
        for(vector <int> &v : edges)
        {
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }
        queue <int> q;
        for(int i = 0; i < V; i++)
            if(!indegree[i])
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(int i : adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return topo;
    }
};