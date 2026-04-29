class Solution {
public:
bool ispos(int mid,vector<int>& nums, int k){
    int sm=0;
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){return false;}
        sm+=nums[i];
        if(sm==mid){cnt++;sm=0;}
        else if(sm>mid){cnt++;sm=nums[i];}
    }
    if(sm!=0){cnt++;}
    return cnt<=k; 
}
    int splitArray(vector<int>& nums, int k){
        int n=nums.size();
        int sm=0;
        for(auto it:nums){sm+=it;}
        int low=0,high=sm;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispos(mid,nums,k)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        int mx=0;
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
            if(tot==ans){mx=max(mx,tot);tot=0;}
            else if(tot>ans){mx=max(mx,tot-nums[i]);tot=nums[i];}
        }
        return mx;
    }
};