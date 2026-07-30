class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri){
        int m=tri.size();
        int n=tri[m-1].size();
        vector<int> prv(n);
        prv[0]=tri[0][0];
        for(int i=1;i<m;i++){
            vector<int> cur(n);
            for(int j=0;j<=i;j++){
                int up=INT_MAX;
                int lt=INT_MAX;
                if(j>0){lt=prv[j-1];}
                if(j<i){up=prv[j];}
                cur[j]=tri[i][j]+min(lt,up);
            }
            prv=cur;
        }
        int ans=INT_MAX;
        for(int j=0;j<=m-1;j++){
            ans=min(ans,prv[j]);
        }
        return ans;
    }
};