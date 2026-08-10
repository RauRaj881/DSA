class Solution {
public:
int find_up(int u,vector<int>&parent){
    if(parent[u]==u){return u;}
    return find_up(parent[u],parent);
}
void union_by_size(int u,int v,vector<int>&parent,vector<int>&size){
    int ulp_u=find_up(u,parent);
    int ulp_v=find_up(v,parent);
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
    int largestIsland(vector<vector<int>>& grid){
        int n=grid.size();
        vector<int> parent(n*n);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        vector<int> size(n*n,1);
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p=i*n+j;
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k],nj=j+dy[k];
                        int np=ni*n+nj;
                        if(ni<0||ni>=n||nj<0||nj>=n||grid[ni][nj]==0){continue;}
                        if(find_up(p,parent)!=find_up(np,parent)){
                            union_by_size(p,np,parent,size);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int> st;
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k],nj=j+dy[k];
                        int np=ni*n+nj;
                        if(ni<0||ni>=n||nj<0||nj>=n||grid[ni][nj]==0){continue;}
                        st.insert(find_up(np,parent));
                    }
                int tot=1;
                for(auto it:st){tot+=size[it];}
                mx=max(mx,tot);
                }
            }
        }
        if(mx==0){mx=n*n;}
        return mx;
    }
};