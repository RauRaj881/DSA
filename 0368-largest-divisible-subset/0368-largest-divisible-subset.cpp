class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<pair<int,int>> dp(n);
        for(int i=0;i<n;i++){dp[i]={1,i};}
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j].first+1>=dp[i].first){dp[i]={dp[j].first+1,j};}
                }
            }
        }
        int mx=1,ed=-1;
        for(int i=0;i<n;i++){if(dp[i].first>=mx){mx=dp[i].first;ed=i;}}
        vector<int> ans;
        int cr=ed;
        while(dp[cr].second!=cr){
            ans.push_back(nums[cr]);
            cr=dp[cr].second;
        }
        ans.push_back(nums[cr]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};