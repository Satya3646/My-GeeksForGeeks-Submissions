// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int n, int E, vector<vector<int>>& edges) {
        // code here
        vector <vector <pair <int, int>>> adj(n); // store adjacent node along with weight of the edge.
        for(vector <int> &v : edges)
            adj[v[0]].push_back({v[1], v[2]});
        
        vector <int> ans(n, INT_MAX);
        // pq is used so that we will always go along the path with smallest edge weight.
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
        pq.push({0, 0});
        ans[0] = 0;
    
        while(!pq.empty())
        {
            auto [dist, node] = pq.top(); // extract the dist and node from pq.
            pq.pop();
            
            if(ans[node] < dist) // if the distance of the current node is already smaller than the current path diastance the skip since processing it will not result in minimal distance.
                continue;
            
            for(auto &[i, wt] : adj[node]) // adjacent nodes.
            {
                if(ans[i] > dist + wt) // if distance of adjacent is larger than the dist of parent + weight of edge the dist can be minimised by choosing the parent part.
                {
                    ans[i] = dist + wt; // parent distance + weight of the edge.
                    pq.push({ans[i], i}); // push to queue since its children also need to minimise their distance.
                }
            }
        }
        
        for(int &i : ans) // all the unreachable node will be left as INT_MAX so make their distance as -1.
            if(i == INT_MAX)
                i = -1;
        return ans;
    }
};
