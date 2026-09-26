class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    dp[i][j]=0;
                    st.insert({0,i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!st.empty()){
            vector<int> cr=*st.begin();
            int w=cr[0],x=cr[1],y=cr[2];
            st.erase(st.begin());
            if(dp[x][y]!=w){continue;}
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m){continue;}
                if(dp[nx][ny]>w+1){
                    dp[nx][ny]=w+1;
                    st.insert({w+1,nx,ny});
                }
            }
        }
        return dp;
        
    }
};