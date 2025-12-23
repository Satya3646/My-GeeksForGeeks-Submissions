class Solution {
  public:
    bool bfs(int root, vector <vector <int>> &graph, vector <int> &color)
    {
        queue <int> q;
        color[root] = 1;
        q.push(root);
        while(!q.empty())
        {
            int node = q.front();
            int currentColor = color[node];
            q.pop();
            for(int i : graph[node])
            {
                if(!color[i]) // if neighbor is not colored then color it opposite as current node and push to queue.
                {
                    if(currentColor == 1)
                        color[i] = 2;
                    else
                        color[i] = 1;
                    q.push(i);
                }
                else if(color[i] == currentColor) // if current node is colored (cycle), check if it has the same color as the current node if yes then return false.
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(int n, vector <vector <int>> &edges)
    {
        vector <vector <int>> graph(n);
        for(vector <int> &v : edges)
            graph[v[0]].push_back(v[1]),
            graph[v[1]].push_back(v[0]);
        
        // instead of visited vector we will use a color vector, which can have three states.
        // 0 - not colored yet (unvisited).
        // 1 - color1.
        // 2 - color2.
        vector <int> color(n, 0);

        // if atleast one component return false return false.
        for(int i = 0; i < n; i++)
            if(!color[i] && !bfs(i, graph, color))
                return false;
        return true;
    }
};