class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        pair<int,int> p;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c=grid[i][j];
                if(c-'a'>=0&&c-'a'<=5){cnt++;}
                if(c=='@'){p={i,j};}
            }
        }
        int tar=(1<<cnt)-1;
        queue<vector<int>> q;
        q.push({p.first,p.second,0,0});
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(tar+1,-1)));
        vis[p.first][p.second][0]=1;
        int ans=-1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it[0];
            int y=it[1];
            int mask=it[2];
            int dist=it[3];
            if(mask==tar){ans=dist;break;}
            for(int i=0;i<4;i++){
                int temp=mask;
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!='#'&&vis[nx][ny][temp]==-1){
                    char ch=grid[nx][ny];
                    vis[nx][ny][temp]=1;
                    if(ch>='A'&&ch<='F'){
                        int dt=ch-'A';
                        if(((1<<dt)&(temp))!=0){q.push({nx,ny,temp,dist+1});}
                    }
                    else if(ch>='a'&&ch<='f'){
                        int dt2=ch-'a';
                        temp=(temp|(1<<dt2));
                        q.push({nx,ny,temp,dist+1});
                    }
                    else{
                        q.push({nx,ny,temp,dist+1});
                    }
                }
            }
        }
        return ans;
    }
};