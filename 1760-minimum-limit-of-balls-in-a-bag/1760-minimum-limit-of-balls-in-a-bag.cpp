class Solution {
public:
bool f(int mid,vector<int>&nums,int mxop){
    long long cnt=0;
    for(int i=0;i<nums.size();i++){
        long long x=nums[i]+mid-1;
        cnt+=(x)/mid;
        cnt-=1;
    }
    return cnt<=mxop;
}
    int minimumSize(vector<int>& nums,int mxop){
        int n=nums.size();
        int low=1,high=1e9,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(f(mid,nums,mxop)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};