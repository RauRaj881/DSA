class Solution {
public:
    int alternatingXOR(vector<int>& nums, int trg1, int trg2) {
        int n=nums.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int xr=0;
        int mod=1e9+7;
        mp1[0]++;mp2[0]++;
        for(int i=n-1;i>=0;i--){
            xr=xr^nums[i];
            dp1[i]=mp2[xr^trg1];
            dp2[i]=mp1[xr^trg2];
            mp1[xr]=(mp1[xr]+dp1[i])%(mod);
            mp2[xr]=(mp2[xr]+dp2[i])%(mod);
        }
        return dp1[0];
    }
};