class Solution {
public:
int bfs(int x,int y,int nx,int ny,vector<vector<int>>& forest){
    int m=forest.size();
    int n=forest[0].size();
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int,int>> q;
    q.push({x,y});
    vector<vector<int>> vis(m,vector<int>(n,-1));
    int cnt=-1;
    vis[x][y]=1;
    while(!q.empty()){
        cnt++;
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int crx=it.first;
            int cry=it.second;
            if(crx==nx&&cry==ny){return cnt;}
            for(int k=0;k<4;k++){
                int nr=crx+dx[k];
                int nc=cry+dy[k];
                if(nr<0||nr>=m||nc<0||nc>=n||vis[nr][nc]==1||forest[nr][nc]==0){continue;}
                q.push({nr,nc});
                vis[nr][nc]=1;
            }
        }
    }
    return -1;
}
    int cutOffTree(vector<vector<int>>& forest){
        int m=forest.size();
        int n=forest[0].size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1){
                    v.push_back({forest[i][j],{i,j}});
                }
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        int x=0,y=0;
        for(int i=0;i<v.size();i++){
            int nx=v[i].second.first;
            int ny=v[i].second.second;
            int k=bfs(x,y,nx,ny,forest);
            if(k==-1){return -1;}
            x=nx,y=ny;
            ans+=k;
        }
        return ans;
    }
};