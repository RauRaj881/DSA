class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int hlt){
        int n=grid.size();
        int m=grid[0].size();
        int tot=m*(n-1)+m;
        int k=hlt-1;
        vector<int> dst(tot,INT_MAX);
        if(grid[0][0]==0)dst[0]=0;
        else{dst[0]=1;}
        set<vector<int>> st;
        if(dst[0]<=k){st.insert({dst[0],0,0});}
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!st.empty()){
            vector<int> v=*st.begin();
            int w=v[0],x=v[1],y=v[2];
            st.erase(st.begin());
            if(x==n-1&&y==m-1){return true;}
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int nd=m*nx+ny;
                    int nw=w+(grid[nx][ny]==1?1:0);
                    if(dst[nd]>nw&&nw<=k){
                        st.insert({nw,nx,ny});
                        dst[nd]=nw;
                    }
                }
            }
        }
        return false;
        
    }
};