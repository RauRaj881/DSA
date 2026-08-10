class Solution {
public:
int find_up(int u,vector<int>&parent){
    if(parent[u]==u){return u;}
    return find_up(parent[u],parent);
}
void union_by_rank(int u,int v,vector<int>&parent,vector<int>&rank){{
    int ulp_u=find_up(u,parent);
    int ulp_v=find_up(v,parent);
    if(rank[ulp_v]>rank[ulp_u]){
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v]=ulp_u;
    }
    else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }
}

}
    int removeStones(vector<vector<int>>& s){
        int n=s.size();
        int mxr=0,mxc=0;
        for(int i=0;i<n;i++){
            int r=s[i][0],c=s[i][1];
            mxr=max(mxr,r);mxc=max(mxc,c);
        }
        vector<int> parent(mxr+mxc+2);
        vector<int> rank(mxr+mxc+2,1);
        for(int i=0;i<mxr+mxc+2;i++){
            parent[i]=i;
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            int u=s[i][0];
            int v=s[i][1]+mxr+1;
            union_by_rank(u,v,parent,rank);
            st.insert(u);st.insert(v);
        }
        int comp=0;
        for(auto it:st){if(parent[it]==it){comp++;}}
        return n-comp;
    }
};