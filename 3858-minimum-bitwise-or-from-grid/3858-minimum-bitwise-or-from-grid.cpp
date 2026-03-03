class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=(1<<30)-1;
        for(int i=29;i>=0;i--){
            int cr=(ans^(1<<i));
            bool pos=true;
            for(int j=0;j<m;j++){
                bool pos2=false;
                for(int k=0;k<n;k++){
                    if((cr|grid[j][k])==cr){pos2=true;}
                }
                if(!pos2){pos=false;}
            }
            if(pos){ans=cr;}
        }
        return ans;
    }
};