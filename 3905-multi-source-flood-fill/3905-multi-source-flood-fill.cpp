class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& src){
        queue<tuple<int,int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<src.size();i++){
            int cl=src[i][2];
            int r=src[i][0];
            int c=src[i][1];
            dist[r][c]=0;
            q.push({r,c,0});
            ans[r][c]=cl;
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [r, c, t] = q.front();
            q.pop();
                for(int j=0;j<4;j++){
                    int nr=r+dx[j];
                    int nc=c+dy[j];
                    if(nr>=0&&nr<n&&nc<m&&nc>=0&&dist[nr][nc]==INT_MAX){
                        dist[nr][nc]=t+1;
                        ans[nr][nc]=ans[r][c];
                        q.push({nr,nc,t+1});
                    }
                    else if(nr>=0&&nr<n&&nc<m&&nc>=0&&dist[nr][nc]==t+1){
                        ans[nr][nc]=max(ans[nr][nc], ans[r][c]);
                    }
                }
        }
        return ans;
    }
};