class Solution {
public:
int findup(int u,vector<int>&parent){
    if(parent[u]==u){return u;}
    return parent[u]=findup(parent[u],parent);
}
void union_by_rank(int u,int v,vector<int>&parent,vector<int>&rank){
    int ulp_u=findup(u,parent);
    int ulp_v=findup(v,parent);
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& acn){
        int n=acn.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++){parent[i]=i;}
        vector<int> rank(n,1);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<acn[i].size();j++){
                if(mp.count(acn[i][j])){
                    union_by_rank(i,mp[acn[i][j]],parent,rank);
                }
                else{
                    mp[acn[i][j]]=i;
                }
            }
        }
        vector<vector<string>> v(n);
        for(auto it:mp){
            string cr=it.first;
            int nd=findup(it.second,parent);
            v[nd].push_back(cr);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(v[i].empty()){continue;}
            vector<string> tp;
            tp.push_back(acn[i][0]);
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size();j++){
                tp.push_back(v[i][j]);
            }
            ans.push_back(tp);
        }
        return ans;
    }
};