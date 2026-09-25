class Solution {
public:
bool f(int mid,vector<int>&nums,int k){
    int cnt=0;
    int sm=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){return false;}
        sm+=nums[i];
        if(sm>mid){cnt++;sm=nums[i];}
    }
    cnt++;
    return cnt<=k;
}
    int splitArray(vector<int>& nums, int k){
        int m=nums.size();
        int low=0,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,nums,k)){
                ans=mid;high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};