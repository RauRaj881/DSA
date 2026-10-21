class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>> s;
        s.insert({0,k});
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }
         vector<int> res(n+1,1e9);
         res[k]=0;
         vector<int> visited(n+1,0);
        while(!s.empty()){
            auto temp=*(s.begin());
            int time=temp.first;
            int node=temp.second;
            visited[node]=1;
            s.erase(temp);
            for(auto it:adj[node]){    
                int nexn=it.first;
                int tottime=it.second+time;
                if(tottime < res[nexn]){
                    res[nexn]=tottime;
                    s.insert({tottime,nexn});
                }
            }
        }
        //for(int i=1;i<=n;i++){
          //  if(visited[i]==0){return -1;}
        //}
        int maxTime = 0;
for (int i = 1; i <= n; i++) {
    if (res[i] == 1e9) return -1;
    maxTime = max(maxTime, res[i]);
}
return maxTime;
    }
};