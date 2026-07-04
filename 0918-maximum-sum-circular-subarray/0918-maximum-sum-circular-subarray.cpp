class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int n=nums.size();
        int mx=INT_MIN;
        int sm=0;
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
            sm+=nums[i];
            mx=max(mx,sm);
            if(sm<0){sm=0;}
        }
        int mn=0;
        int sm2=0;
        for(int i=0;i<n;i++){
            sm2+=nums[i];
            mn=min(mn,sm2);
            if(sm2>0){sm2=0;}
        }
        if(mx<0){return mx;}
        return max(mx,tot-mn);
    }
};