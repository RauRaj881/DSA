class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        int n=digitSum.size();
        for(int i=0;i<n;i++){
            if(digitSum[i]>31){return 0;}
        }
        vector<vector<int>> ds(32);
        for(int i=0;i<=5000;i++){
            int x=i;
            int sm=0;
            while(x!=0){
                sm+=x%10;
                x/=10;
            }
            ds[sm].push_back(i);
        }
        for(int i=0;i<32;i++){
            sort(ds[i].begin(),ds[i].end());
        }
        vector<vector<int>> dp(n,vector<int>(5001,0));
        for(int i=0;i<ds[digitSum[0]].size();i++){
            dp[0][ds[digitSum[0]][i]]=1;
        }
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            int vl=digitSum[i];
            int pvl=digitSum[i-1];
           vector<int> pre(ds[pvl].size());
           pre[0] = dp[i-1][ds[pvl][0]];
           for(int k = 1; k < ds[pvl].size(); k++){
           pre[k] = (pre[k-1] + dp[i-1][ds[pvl][k]]) % mod;
           }
            for(int j=0;j<ds[vl].size();j++){
                int nm=ds[vl][j];
                auto it=upper_bound(ds[pvl].begin(),ds[pvl].end(),nm);
                int idx=it-ds[pvl].begin();
                if(idx > 0){
        dp[i][nm] = pre[idx-1]%(mod);
    } else {
        dp[i][nm] = 0;
    }
            }
        }
        int ans=0;
        int vl=digitSum[n-1];
        for(int i=0;i<ds[vl].size();i++){
            ans=(ans+dp[n-1][ds[vl][i]])%(mod);
        }
        return ans;
    }
};