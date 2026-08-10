class Solution {
public:
int cnt=0;
void merge(int l,int mid,int r,vector<int>&nums){
    int n=nums.size();
    vector<int> tp;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if((long long)nums[i]>2LL*nums[j]){cnt+=mid-i+1;j++;}
        else{i++;}
    }
    i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(nums[i]>nums[j]){tp.push_back(nums[j]);j++;}
        else{tp.push_back(nums[i]);i++;}
    }
    while(i<=mid){tp.push_back(nums[i]);i++;}
    while(j<=r){tp.push_back(nums[j]);j++;}
    for(int i=0;i<tp.size();i++){
        nums[i+l]=tp[i];
    }
}
void mergesort(int l,int r,vector<int>&nums){
    if(l==r){return;}
    int mid=(l+r)/2;
    mergesort(l,mid,nums);
    mergesort(mid+1,r,nums);
    merge(l,mid,r,nums);
}
    int reversePairs(vector<int>& nums){
        int n=nums.size();
        mergesort(0,n-1,nums);
        return cnt;
    }
};