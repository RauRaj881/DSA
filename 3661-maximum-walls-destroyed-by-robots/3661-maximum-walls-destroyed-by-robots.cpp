class Solution {
public:
    int maxWalls(vector<int>& rob, vector<int>& dist, vector<int>& w){
        int n=rob.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={rob[i],dist[i]};
        }
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        int m=w.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        int inf=INT_MAX;
        for(int i=0;i<n;i++){
            int nv=(i==0?-inf:v[i-1].first);
            int nv2=(i==0?0:v[i-1].second);
            int nd=(i>0?dp[i-1][0]:0);
            int nd2=(i>0?dp[i-1][1]:0);
                int llr=max(v[i].first-v[i].second,(nv+1));
                int rlr=max(v[i].first-v[i].second,min(nv+nv2+1,v[i].first));
                
                int x=upper_bound(w.begin(),w.end(),v[i].first)-w.begin();
                int y=lower_bound(w.begin(),w.end(),llr)-w.begin();
                dp[i][0]=max(dp[i][0],nd+x-y);
                
                x=upper_bound(w.begin(),w.end(),v[i].first)-w.begin();
                y=lower_bound(w.begin(),w.end(),rlr)-w.begin();
                dp[i][0]=max(dp[i][0],nd2+x-y); 

                int lrr=min(v[i].first+v[i].second,(i+1==n?inf:v[i+1].first-1));
                int rrr=lrr;

                x=upper_bound(w.begin(),w.end(),lrr)-w.begin();
                y=lower_bound(w.begin(),w.end(),v[i].first)-w.begin();
                dp[i][1]=max(dp[i][1],nd+x-y);
                dp[i][1]=max(dp[i][1],nd2+x-y);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};