class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Code here
        vector <vector <pair <int, int>>> adj(n);
        for(vector <int> &v : flights) // node --> {neighbor, cost of path}.
            adj[v[0]].push_back({v[1], v[2]});
        
        
        vector <int> price(n, INT_MAX); // stores minimum price to reach node.
        queue <pair <int, int>> q; 
        q.push({src, 0});
        price[src] = 0;

        while(!q.empty() && k-- >= 0) // continue BFS till queue empty or stops > k.
        {
            int qs = q.size();
            while(qs--) // current layer (stops).
            {
                auto [node, cost] = q.front(); // extract.
                q.pop();
                
                for(auto &[i, wt] : adj[node]) // neighbors.
                {
                    if(price[i] > cost + wt) // if path through parent to current node is cheaper the choose that path.
                    {
                        price[i] = cost + wt;
                        q.push({i, price[i]});
                    }
                }
            }
        }

        /* Here we have two problems : 
        1. If we can reach the destination from the source within k steps or not.
        2. If its reachable then what is the minimum price to reach.
        To ensure only k steps are taken we will use BFS with constrained steps this
        will make sure that only the node within k steps of srouce node are visited.
        Next we will check the neighbors, if the cost to reach neighbor is greater than
        the path through the parent to current node the update cost and push to queue. */

        if(price[dst] != INT_MAX)
            return price[dst];
        return -1;
    }
};