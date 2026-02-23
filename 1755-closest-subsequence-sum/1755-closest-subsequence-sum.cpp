//TLE
/*class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_set<int> dp;
        int mn=abs(goal);
        dp.insert(nums[0]);
        dp.insert(0);
        for(int i=1;i<n;i++){
            unordered_set<int> ndp;
            for(auto it:dp){
                ndp.insert(it);
                ndp.insert(nums[i]);
                ndp.insert(it+nums[i]);
                int a=abs(it-goal);
                int b=abs(nums[i]-goal);
                int c=abs(it+nums[i]-goal);
                mn=min(mn,min(a,b));
                mn=min(mn,c);
            }
            dp=ndp;
        }
        return mn;
    }
};*/

class Solution {
public:
void storesm(int st,int r,map<int, int>&dp,int crsm,vector<int>&nums){
    if(st>r){
        dp[crsm]++;
        return;
    }
    storesm(st + 1, r, dp,crsm,nums);
    storesm(st + 1, r, dp,crsm + nums[st],nums);
}
void storesm2(int st,int r,unordered_map<int, int>&dp,int crsm,vector<int>&nums){
    if(st>r){
        dp[crsm]++;
        return;
    }
    storesm2(st + 1, r, dp,crsm,nums);
    storesm2(st + 1, r, dp,crsm + nums[st],nums);
}
    int minAbsDifference(vector<int>& nums, int x) {
        int n=nums.size();
        map<int,int> dp1;
        storesm(0, n/2-1, dp1,0,nums);
        map<int,int> dp2;
        //dp2.reserve(1 << 20);
        storesm(n / 2, n - 1, dp2,0,nums);
        int ans = 0;
        int mn=1e9;
        for(auto it2 : dp2){
           int right = it2.first;
           auto it = dp1.lower_bound(x - right);
           if(it != dp1.end()){
             int left = it->first;
             mn = min(mn, abs((left + right) - x));
            }

            if(it != dp1.begin()){
                auto pit = prev(it);
                int left = pit->first;
                mn = min(mn, abs((left + right) - x));
               }
        }
        return mn; 
    }
};