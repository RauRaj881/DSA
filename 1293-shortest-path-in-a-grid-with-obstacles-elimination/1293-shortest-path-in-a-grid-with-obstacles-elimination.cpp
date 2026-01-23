class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1&&m==1){return 0;}
        queue<vector<int>> q;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=-1;
        vis[0][0][k]=1;
        q.push({0,0,k,0});
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int x=v[0],y=v[1],rem=v[2],dist=v[3];
            if(x==n-1&&y==m-1){ans=dist;break;}
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(grid[nx][ny]==1&&rem>0&&vis[nx][ny][rem-1]==-1){
                        if(rem>0){vis[nx][ny][rem-1]=1;q.push({nx,ny,rem-1,dist+1});}
                    }
                    else if(grid[nx][ny]==0&&vis[nx][ny][rem]==-1){
                        vis[nx][ny][rem]=1;
                        q.push({nx,ny,rem,dist+1});
                    }
                }
            }
        }
        return ans;
    }
};