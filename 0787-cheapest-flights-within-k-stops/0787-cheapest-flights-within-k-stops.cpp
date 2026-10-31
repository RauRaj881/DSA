class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>> dp(n,vector<int>(k+2,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        dp[src][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int w=curr.first;
            int nd=curr.second.first;
            int stops=curr.second.second;
            if(nd==dst){return w;}
            if(dp[nd][stops]!=w){continue;}
            for(auto it:adj[nd]){
                int nexnd=it.first;
                int nexw=it.second;
                if(stops<=k&&dp[nexnd][stops+1]>w+nexw){
                    dp[nexnd][stops+1]=w+nexw;
                    pq.push({w+nexw,{nexnd,stops+1}});
                }
            }
        }
        return -1;
    }
};