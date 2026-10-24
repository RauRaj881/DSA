class Solution {
public:
    int jobScheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit){
        int n=profit.size();
        vector<int> suf(n,0);
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end());
        vector<int> start(n);
        for(int i=0;i<n;i++){
            start[i]=v[i][0];
        }
        for(int i=n-1;i>=0;i--){
            int ed=v[i][1];
            auto it=lower_bound(start.begin(),start.end(),ed);
            int nottake=0;
            if(i<n-1){
                nottake=suf[i+1];
            }
            int take=0;
            take+=v[i][2];
            if(it!=start.end()){
                int idx=it-start.begin();
                take+=suf[idx];
            }
            suf[i]=max(take,nottake);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,suf[i]);
        }
        return ans;
    }
};