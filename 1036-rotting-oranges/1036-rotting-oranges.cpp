class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int x=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int days=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nexr=temp.first+drow[i];
                    int nexc=temp.second+dcol[i];
                    if(nexr<=m-1 && nexr>=0 && nexc<=n-1 && nexc>=0 && grid[nexr][nexc]==1){
                        grid[nexr][nexc]=2;
                        q.push({nexr,nexc});
                    }
                }
            }
            days++; 
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(days==0){return 0;}
        return days-1;
    }
};