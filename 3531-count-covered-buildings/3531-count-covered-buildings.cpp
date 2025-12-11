class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minrow(n+1,n+1);
        vector<int> maxrow(n+1,0);
        vector<int> mincol(n+1,n+1);
        vector<int> maxcol(n+1,0);
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            minrow[y]=min(minrow[y],x);
            maxrow[y]=max(maxrow[y],x);
            mincol[x]=min(mincol[x],y);
            maxcol[x]=max(maxcol[x],y);
        }
        int cnt=0;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            if(x>minrow[y]&&x<maxrow[y]&&y>mincol[x]&&y<maxcol[x]){cnt++;}
        }
        return cnt;
    }
};