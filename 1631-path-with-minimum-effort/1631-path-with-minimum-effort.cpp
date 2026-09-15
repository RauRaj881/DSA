class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h){
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> dst(n,vector<int>(m,INT_MAX));
        dst[0][0]=0;
        set<vector<int>> st;
        st.insert({0,0,0});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!st.empty()){
            vector<int> tp=*st.begin();
            st.erase(st.begin());
            int w=tp[0],x=tp[1],y=tp[2];
            if(x==n-1&&y==m-1){return w;}
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m){continue;}
                int nw=max(w,abs(h[x][y]-h[nx][ny]));
                if(nw<dst[nx][ny]){
                    dst[nx][ny]=nw;
                    st.insert({nw,nx,ny});
                }
            }
        }
        return -1;
        
    }
};