class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> visited(n*n,0);
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        set<pair<int,pair<int,int>>> s;
        s.insert({grid[0][0],{0,0}});
        int mintime=0;
        while(!s.empty()){
            auto temp=*(s.begin());
            int row=temp.second.first;
            int col=temp.second.second;
            int time=temp.first;
            s.erase(temp);
            int node=row*n+col;
            visited[node]=1;
            mintime=max(mintime,time);
            if(row ==n-1 && col==n-1){
                return mintime;
            }
            for(int i=0;i<4;i++){
                int nexr=row+drow[i];
                int nexc=col+dcol[i];
                if(nexr>=0 && nexc>=0 && nexr<n && nexc<n){
                if(visited[nexr*n+nexc]==0){
                    visited[nexr*n+nexc]=1;
                    s.insert({grid[nexr][nexc],{nexr,nexc}});
                }
                }
            }
        }
        return 0;
    }
};