/*class Solution {
public:
bool ispossible(long long mid,vector<vector<pair<long long,long long>>> &adj, vector<bool>& online,long long k,int n){
    set<pair<long long,long long>> s;
    s.insert({0,0});
    while(!s.empty()){
        auto it=*s.begin();
        long long dist=it.first;
        long long nd=it.second;
        s.erase(it);
        if(nd==n-1){return true;}
        for(auto ig:adj[nd]){
            long long v=ig.first;
            long long w=ig.second;
            if(dist+w<=k&&w>=mid&&online[v]==true){s.insert({dist+w,v});}
        }
    }
    return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<long long,long long>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        long long low=0,high=1e9;
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,adj,online,k,n)){
                ans=mid;low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};*/
#define ll long long
class Solution {
private:
    bool isPathPossible(unordered_map<int, vector<pair<int, int>>>& graph, ll k,
                        ll n, ll mid) {
        // This function checks for existence of path bw 0 & n-1 & is within k
        // cost
        vector<ll> dist(n, k + 1);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (pq.size()) {
            ll cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (cost > dist[node]) // Very Imp. For Pruning.
                continue;

            if (node == n - 1)
                return true;

            for (auto childData : graph[node]) {
                int childNode = childData.first;
                ll childCost = childData.second;

                if (childCost < mid)
                    continue;

                if ((childCost + dist[node]) < dist[childNode]) {
                    dist[childNode] = childCost + dist[node];
                    pq.push({childCost, childNode});
                }
            }
        }

        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        ll start = 0, end = 1000000000, ans = -1, n = online.size();
        // Construct Graph:
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto x : edges) {
            int node1 = x[0], node2 = x[1], cost = x[2];
            if (!online[node1] || !online[node2])
                continue;
            graph[node1].push_back({node2, cost});
        }

        while (start <= end) {
            ll mid = (start + end) / 2;
            // We will pick all the edges with wt >= mid as this has to be
            // answer.
            if (isPathPossible(graph, k, n, mid)) {
                ans = max(ans, mid);
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return ans;
    }
};