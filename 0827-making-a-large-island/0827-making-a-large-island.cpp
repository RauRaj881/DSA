class Solution {
public:
int findupar(int node,vector<int> & parent){
    if(parent[node]==node){return node;}
    return findupar(parent[node],parent);
}
void disjoint(int u,int v,vector<int> & parent,vector<int> &size){
    int ulp_u=findupar(u,parent);
    int ulp_v=findupar(v,parent);
    if(ulp_u==ulp_v){return;}
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else {
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> parent(n*n);
        vector<int> size(n*n,1);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
            int node =row*n+col;
            if(grid[row][col]==1){
            for(int i=0;i<4;i++){
                int nexr=row+drow[i];
                 int nexc=col+dcol[i];
                 int adjnod=nexr*n+nexc;
                 if(nexr>=0 && nexr<n && nexc>=0 && nexc<n){
                 if(grid[nexr][nexc]==1){
                 if(findupar(node,parent)!=findupar(adjnod,parent)){
                    disjoint(node,adjnod,parent,size);
                 }
                 }
            }
            }
            }
            }
        }
        int maxno=0;
        for(int checkr=0;checkr<n;checkr++){
            for(int checkc=0;checkc<n;checkc++){
                int checknod=checkr*n+checkc;
            if(grid[checkr][checkc]==0){
                set<int> components;
            for(int i=0;i<4;i++){
                int nexxr=checkr+drow[i];
                 int nexxc=checkc+dcol[i];
                 int checkadjnod=nexxr*n+nexxc;
                 if(nexxr>=0 && nexxr<n && nexxc>=0 && nexxc<n){
                 if(grid[nexxr][nexxc]==1){
                    if(findupar(checknod,parent)!=findupar(checkadjnod,parent)){
                        int pofnod=findupar(checkadjnod,parent);
                        components.insert(pofnod);
                    }
                 }
        }
            }
            int totalsize=1;
            for(auto it:components){
                totalsize+=size[it];
            }
            maxno=max(maxno,totalsize);
            }
            }
        }
        for(int i=0;i<n*n;i++){
    maxno = max(maxno, size[findupar(i, parent)]);
}
return maxno;

        return maxno;
    }
};