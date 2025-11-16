class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long> start(n);
        vector<long long> end(n);
        start[0]=0;end[n-1]=n-1;
        for(int i=1;i<n;i++){
            start[i]=(nums[i]>=nums[i-1])?start[i-1]:i;
        }
        for(int i=n-2;i>=0;i--){
            end[i]=(nums[i]<=nums[i+1])?end[i+1]:i;
        }
        vector<long long> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long st=start[i];
            long long len=i-st+1;
            dp[i]+=((len)*(len+1))/2;
            if(st>0){dp[i]+=dp[st-1];}
        }
        long long q=queries.size();
        vector<long long> ans(q,0);
        for(int i=0;i<q;i++){
            long long l=queries[i][0];
            long long r=queries[i][1];
            ans[i]+=dp[r]-((l>0)?dp[l-1]:0);
            ans[i]-=(l-start[l])*(min(end[l],r)-l+1);
        }
        return ans;
    }
};