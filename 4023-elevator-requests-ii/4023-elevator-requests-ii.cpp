#define ll long long
class Solution {
public:
    long long elevatorRequests(int n, int st,vector<int>& r){
        bool has=false;
        for(auto it:r){if(it==st){has=true;}}
        if(!has)(r.push_back(st));
        int m=r.size();
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(m,vector<ll>(2,1e17)));
        int idx=-1;
        sort(r.begin(),r.end());
        for(int i=0;i<m;i++){
            if(r[i]==st){idx=i;}
        }
        dp[idx][idx][0]=0;dp[idx][idx][1]=0;
        for(int len=1;len<=m;len++){
            for(int i=0;i+len-1<m;i++){
                int j=i+len-1;
                int rem=m-(len);
                if(dp[i][j][0]!=1e17){
                    if(i>0){
                        int df1=r[i]-r[i-1];
                        dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][0]+(ll)df1*rem);
                    }
                    if(j<m-1){
                        int df1=r[j+1]-r[i];
                        dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][0]+(ll)df1*rem);
                    }
                }
                if(dp[i][j][1]!=1e17){
                    if(i>0){
                        int df1=r[j]-r[i-1];
                        dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][1]+(ll)df1*rem);
                    }
                    if(j<m-1){
                        int df1=r[j+1]-r[j];
                        dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][1]+(ll)df1*rem);
                    }
                }
            }
        }
        return min(dp[0][m-1][0],dp[0][m-1][1]);   
    }
};