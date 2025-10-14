class Solution {
public:
int f(int index,vector<pair<int,pair<int,int>>> &st,int n,int count, vector<vector<int>> &dp){
    if(index==n||count==2){return 0;}
    if(dp[index][count]!=-1){return dp[index][count];}
    int l = index + 1, r = n - 1, next = n;
    int lastended = st[index].second.first;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (st[mid].first > lastended) {
                next = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    int take=st[index].second.second + f(next, st, n, count + 1, dp);
    int nottake=f(index+1,st,n,count,dp);
    return dp[index][count]=max(take,nottake);
}
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<pair<int,pair<int,int>>> st(n);
        for(int i=0;i<n;i++){
            st[i]={events[i][0],{events[i][1],events[i][2]}};
        }
        vector<vector<int>> dp(n,vector<int>(3,-1));
        sort(st.begin(),st.end());
        return f(0,st,n,0,dp);
    }
};