class Solution {
public:
int fup(int x,vector<int> &parent){
    if(parent[x]==x){return x;}
    return fup(parent[x],parent);
}
int fp(int x,vector<int>&parent,vector<int>&parity){
    if(parent[x]==x){return parity[x];}
    int p=parent[x];
    int vl=fp(p,parent,parity);
    return parity[x]^vl;
}
void union_by_rank(int u,int v,vector<int> &parent,vector<int>&rank,vector<int>&parity,int w){
    int ulp_u=fup(u,parent);
    int ulp_v=fup(v,parent);
    int x=fp(u,parent,parity);
    int y=fp(v,parent,parity);
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
        parity[ulp_v]=(x^y^w);
    }
    else if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
        parity[ulp_u]=(x^y^w);
    }
    else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
        parity[ulp_v]=(x^y^w);
    }
}
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges){
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> parity(n,0);
        int ans=0;
        vector<int> rank(n,1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            int ulp_u=fup(u,parent);
            int ulp_v=fup(v,parent);
            int x=fp(u,parent,parity);
            int y=fp(v,parent,parity);
            if(ulp_u==ulp_v){if((x^y)==w){ans++;}}
            else{
                ans++;
                union_by_rank(u,v,parent,rank,parity,w);
            }
        }
        return ans;
    }
};