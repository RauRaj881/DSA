class Solution {
public:
void dijkstra(int nd,vector<vector<pair<int,int>>> &adj,vector<vector<long long>> &mnc){
    set<pair<int,int>> s;
    s.insert({0,nd});
    while(!s.empty()){
        auto it=*s.begin();
        int cst=it.first;
        int nod=it.second;
        s.erase(it);
        for(auto it2:adj[nod]){
            int nexnod=it2.first;
            int nexcst=it2.second;
            if(cst+nexcst<mnc[nd][nexnod]){
                s.erase({mnc[nd][nexnod],nexnod});
                mnc[nd][nexnod]=cst+nexcst;
                s.insert({mnc[nd][nexnod],nexnod});
            }
        }
    }
}
    long long minimumCost(string src, string trg, vector<string>& org, vector<string>& chd, vector<int>& cst) {
        int n=org.size();
        unordered_map<string,int> mp;
        int id=0;
        for(int i=0;i<n;i++){
            string u=org[i];
            string v=chd[i];
            if(!mp.count(u)){mp[u]=id;id++;}
            if(!mp.count(v)){mp[v]=id;id++;}
        }
        vector<vector<pair<int,int>>> adj(id);
        for(int i=0;i<n;i++){
            int a=mp[org[i]];
            int b=mp[chd[i]];
            int w=cst[i];
            adj[a].push_back({b,w});
        }
        vector<vector<long long>> mnc(id,vector<long long>(id,1e18));
        for(int i=0;i<id;i++){
            dijkstra(i,adj,mnc);
        }
        unordered_set<int> len;
        for(int i=0;i<n;i++){
            int sz=org[i].size();
            len.insert(sz);
        }
        int m=src.size();
        vector<long long> dp(m+1,1e18);
        dp[m]=0;
        for(int i=m-1;i>=0;i--){
            if(src[i]==trg[i]){
                dp[i]=dp[i+1];
            }
            for(auto it:len){
                int j=i-1+it;
                if(j>=m){continue;}
                string temp=src.substr(i,it);
                string temp2=trg.substr(i,it);
                if(!mp.count(temp)||!mp.count(temp2)){continue;}
                int x=mp[temp];
                int y=mp[temp2];
                dp[i]=min(dp[i],mnc[x][y]+dp[j+1]);
            }
        }
        return dp[0]==1e18?-1:dp[0];
    }
};