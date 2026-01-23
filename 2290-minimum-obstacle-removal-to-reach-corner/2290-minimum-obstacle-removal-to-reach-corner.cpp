class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<pair<int,pair<int,int>>> s;
        s.insert({0,{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int ans=-1;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        vis[0][0]=1;
        while(!s.empty()){
            auto it=(*s.begin());
            s.erase(it);
            int cnt=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1&&y==m-1){ans=cnt;break;}
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==-1){
                    if(grid[nx][ny]==1){
                        s.insert({cnt+1,{nx,ny}});
                    }
                    else{s.insert({cnt,{nx,ny}});}
                    vis[nx][ny]=1;
                }
            }
        }
        return ans;
    }
};