class Solution {
public:
int find_up(int u,vector<int>& parent){
    if(parent[u]==u){return u;}
    return find_up(parent[u],parent);
}
void union_by_rank(int u,int v,vector<int>& parent,vector<int>& rank){
    int ulp_u=find_up(u,parent);
    int ulp_v=find_up(v,parent);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc){
        int n=acc.size();
        unordered_map<string,int> mp;
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++){parent[i]=i;}
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string gmail=acc[i][j];
                if(mp.count(gmail)){
                    union_by_rank(i,mp[gmail],parent,rank);
                }
                else{
                    mp[gmail]=i;
                }
            }
        }
        vector<vector<string>> v(n);
        for(auto it:mp){
            string cr=it.first;
            int u=it.second;
            int ulp_u=find_up(u,parent);
            v[ulp_u].push_back(cr);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(v[i].empty()){continue;}
            vector<string> tp;
            tp.push_back(acc[i][0]);
            sort(v[i].begin(),v[i].end());
            for(auto it:v[i]){
                tp.push_back(it);
            }
            ans.push_back(tp);
        }
        return ans;
    }
};