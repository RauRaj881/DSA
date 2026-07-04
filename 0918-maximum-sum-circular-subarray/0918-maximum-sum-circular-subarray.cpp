class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int n=nums.size();
        int mx=INT_MIN;
        int sm=0;
        int tot=0;
        int cntn=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){cntn++;}
            tot+=nums[i];
            sm+=nums[i];
            mx=max(mx,sm);
            if(sm<0){sm=0;}
        }
        int mn=0;
        int sm2=0;
        int mx2=INT_MIN;
        for(int i=0;i<n;i++){
            mx2=max(mx2,nums[i]);
            sm2+=nums[i];
            mn=min(mn,sm2);
            if(sm2>0){sm2=0;}
        }
        if(cntn==n){return mx2;}
        return max(mx,tot-mn);
    }
};