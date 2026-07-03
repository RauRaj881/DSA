class Solution {
public:
bool ispossible(int mid,vector<vector<int>>& grid,vector<vector<int>> &v){
    int n=grid.size();
    int m=grid[0].size();
    //if (v[0][0] < mid) return false;
    queue<pair<int,int>> q;
    if(v[0][0]>=mid)q.push({0,0});
    vector<vector<int>> vis(n,vector<int>(m,-1));
    vis[0][0]=1;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(x==n-1&&y==m-1){return true;}
        for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                if(vis[nx][ny]==-1&&v[nx][ny]>=mid){vis[nx][ny]=1;q.push({nx,ny});}
            }
        }
    }
    return false;
    
}
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1){return 0;}
        vector<vector<int>> v(n,vector<int>(m,m+n));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){q.push({i,j});v[i][j]=0;}
            }
        }
        int level=0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            level++;
            int sz=q.size();
            for(int k=0;k<sz;k++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(v[nx][ny]>level){v[nx][ny]=level;q.push({nx,ny});}
                }
            }
            }
        }
        int low=0,high=m+n;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(mid,grid,v)){ans=mid;low=mid+1;}
            else{high=mid-1;}
        }
        return ans;

    }
};