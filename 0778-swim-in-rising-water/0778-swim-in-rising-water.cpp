class Solution {
public:
    int swimInWater(vector<vector<int>>& grid){
        int n=grid.size();
        vector<vector<int>> dst(n,vector<int>(n,INT_MAX));
        dst[0][0]=grid[0][0];
        set<vector<int>> st;
        st.insert({dst[0][0],0,0});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!st.empty()){
            vector<int> tp=*st.begin();
            st.erase(st.begin());
            int w=tp[0],r=tp[1],c=tp[2];
            if(dst[r][c]!=w){continue;}
            if(r==n-1&&c==n-1){return w;}
            for(int i=0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(nr<0||nr>=n||nc<0||nc>=n){continue;}
                int crw=max(w,grid[nr][nc]);
                if(dst[nr][nc]>crw){
                    dst[nr][nc]=crw;
                    st.insert({crw,nr,nc});
                }
            }
        }
        return -1;
    }
};