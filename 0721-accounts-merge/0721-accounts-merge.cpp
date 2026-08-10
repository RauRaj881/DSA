class Solution {
public:
int findUpar(int node,vector<int> & parent){
    if(parent[node]==node){return node;}
    return findUpar(parent[node],parent);
}
void disjoint(int u,int v,vector<int> & parent,vector<int> &rank){
    int ulp_u=findUpar(u,parent);
    int ulp_v=findUpar(v,parent);
    //if(ulp_u==ulp_v){return;}
    if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]==rank[ulp_v]){
        parent[ulp_u]=ulp_v;
        rank[ulp_v]++;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
       vector<int> rank(n,0);
       unordered_map<string,int> mailtonod;
       for(int i=0;i<accounts.size();i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mailtonod.find(mail)==mailtonod.end()){
                mailtonod[mail]=i;
            }
            else {
                disjoint(i,mailtonod[mail],parent,rank);
            }
        }
       }
       vector<vector<string>> s(n);
       for(auto it:mailtonod){
        int node=it.second;
        string p=it.first;
        int y=findUpar(node,parent);
        s[y].push_back(p);
       }
       vector<vector<string>> ans;
       for(int i=0;i<n;i++){
        if(s[i].size()==0){continue;}
        sort(s[i].begin(),s[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it:s[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
       }
       return ans;
    }
};