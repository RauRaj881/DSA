class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& et) {
        int m=maze.size(),n=maze[0].size();
        int sti=et[0],stj=et[1];
        queue<vector<int>> q;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(vis[0][i]==false&&maze[0][i]=='.'&&(0!=sti||i!=stj)){
                vis[0][i]=true;
                q.push({0,i,0});
            }
            if(vis[m-1][i]==false&&maze[m-1][i]=='.'&&((m-1)!=sti||i!=stj)){
                vis[m-1][i]=true;
                q.push({m-1,i,0});
            }
        }
        for(int i=0;i<m;i++){
            if(vis[i][0]==false&&maze[i][0]=='.'&&(i!=sti||0!=stj)){
                vis[i][0]=true;
                q.push({i,0,0});
            }
            if(vis[i][n-1]==false&&maze[i][n-1]=='.'&&(i!=sti||(n-1)!=stj)){
                vis[i][n-1]=true;
                q.push({i,n-1,0});
            }
        }
        if(q.empty()){return -1;}
        //int level=-1;
        while(!q.empty()){
            //level++;
            vector<int> yh=q.front();
            int ci=yh[0];
            int cj=yh[1];
            int level=yh[2];
            q.pop();
            if(ci==sti&&cj==stj){return level;}
            for(int i=0;i<4;i++){
                int ni=ci+dx[i];
                int nj=cj+dy[i];
                if(ni>=0&&ni<m&&nj>=0&&nj<n&&maze[ni][nj]=='.'&&vis[ni][nj]==false){
                    q.push({ni,nj,level+1});
                    vis[ni][nj]=true;
                }
            }
        }
        return -1;
    }
};