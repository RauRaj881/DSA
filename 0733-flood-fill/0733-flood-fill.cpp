class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int ori=image[sr][sc];
        if(ori==color){return image;}
        q.push({sr,sc});
        image[sr][sc]=color;
        int m=image.size();
        int n=image[0].size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nexr=drow[i]+temp.first;
                    int nexc=dcol[i]+temp.second;
                    if(nexr>=0 && nexr<=m-1 && nexc>=0 && nexc<=n-1 && image[nexr][nexc]==ori){
                        image[nexr][nexc]=color;
                        q.push({nexr,nexc});
                    }
                }
            }
        }
        return image;
    }
};