class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<pair<int, int>> adj[n];
        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        int stops = 0;
        while (!q.empty() && stops <= k){
            int sz = q.size(); 
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (auto& iter : adj[node]) {
                    int adjNode = iter.first;
                    int edW = iter.second;
                    if (cost + edW < dist[adjNode]) {
                        dist[adjNode] = cost + edW;
                        q.push({adjNode, cost + edW});
                    }
                }
            }
            stops++;
        }
        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};