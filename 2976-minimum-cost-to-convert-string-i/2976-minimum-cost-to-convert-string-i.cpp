class Solution {
public:
void dfs(int start,vector<vector<pair<int,int>>> &adj,vector<vector<int>> &mnc){
    set<pair<int,int>> s;
    s.insert({0,start});
    while(!s.empty()){
        auto it=*s.begin();
        int nd=it.second;
        int cst=it.first;
        s.erase(it);
        for(auto it2:adj[nd]){
            int nexnd=it2.first;
            int nexcst=it2.second;
            if(mnc[start][nexnd]>cst+nexcst){
                s.erase({mnc[start][nexnd],nexnd});
                mnc[start][nexnd]=cst+nexcst;
                s.insert({cst+nexcst,nexnd});
            }
        }
    }
}
    long long minimumCost(string src, string trg, vector<char>& org, vector<char>& chgd, vector<int>& cst) {
        vector<vector<pair<int,int>>> adj(26);
        int t=chgd.size();
        for(int i=0;i<t;i++){
            char o=org[i];
            char c=chgd[i];
            adj[o-'a'].push_back({c-'a',cst[i]});
        }
        vector<vector<int>> mnc(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++){
            dfs(i,adj,mnc);
        }
        long long tot=0;
        for(int i=0;i<src.size();i++){
            char f=src[i];
            char g=trg[i];
            if(f==g){continue;}
            if(mnc[f-'a'][g-'a']==INT_MAX){return -1;}
            else{tot+=mnc[f-'a'][g-'a'];}
        }
        return tot;
    }
};