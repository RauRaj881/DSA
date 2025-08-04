class Solution {
public:
int findUpar(int node,vector<int> & parent){
    if(parent[node]==node){return node;}
    return findUpar(parent[node],parent);
}
void disjoint(int u,int v,vector<int> & parent,vector<int> &rank){
    int ulp_u=findUpar(u,parent);
    int ulp_v=findUpar(v,parent);
    if(ulp_u==ulp_v){return;}
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0,maxcol=0;
        unordered_map<int,int> mp;
        for(auto it:stones){
            int row=it[0];
            int col=it[1];
            maxrow=max(maxrow,row);
            maxcol=max(maxcol,col);
        }
        vector<int> parent(maxrow+2+maxcol);
        vector<int> rank(maxrow+2+maxcol,0);
        for(int i=0;i<=maxrow+1+maxcol;i++){
            parent[i]=i;
        }
        for(int i=0;i<stones.size();i++){
            disjoint(stones[i][0],stones[i][1]+maxrow+1,parent,rank);
            mp[stones[i][0]]=1;
            mp[stones[i][1]+maxrow+1]=1;
        }
        int x=0;
        for(auto it:mp){
            if(parent[it.first]==it.first){x++;}
        }
        return stones.size()-x;
    }
};