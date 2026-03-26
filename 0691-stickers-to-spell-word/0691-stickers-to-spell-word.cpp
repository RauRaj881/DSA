class Solution {
public:
    int minStickers(vector<string>& stickers, string target){
        int t=target.size();
        vector<int> dp((1<<t),INT_MAX);
        dp[0]=0;
        for(int mask=0;mask<(1<<t);mask++){
            if(dp[mask]==INT_MAX){continue;}
            for(int i=0;i<stickers.size();i++){
                int nwmask=mask;
                for(int j=0;j<stickers[i].size();j++){
                    for(int k=0;k<t;k++){
                        if(((nwmask&(1<<k))==0)&&stickers[i][j]==target[k]){
                            nwmask|=(1<<k);
                            break;
                        }
                    }
                }
                dp[nwmask]=min(dp[nwmask],dp[mask]+1);
            }
        }
        if(dp[(1<<t)-1]==INT_MAX){return -1;}
        return dp[(1<<t)-1];
    }
};