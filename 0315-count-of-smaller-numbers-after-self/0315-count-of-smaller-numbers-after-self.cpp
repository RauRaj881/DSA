class Solution {
public:
int cnt=0;
void merge(int l,int mid,int r,vector<pair<int,int>>&arr,vector<int>&ans){
    vector<pair<int,int>> tp;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(arr[i].first>arr[j].first){tp.push_back(arr[j]);j++;}
        else{ans[arr[i].second]+=j-1-mid;tp.push_back(arr[i]);i++;}
    }
    while(i<=mid){tp.push_back(arr[i]);ans[arr[i].second]+=j-mid-1;i++;}
    while(j<=r){tp.push_back(arr[j]);j++;}
    for(int i=0;i<tp.size();i++){
        arr[i+l]=tp[i];
    }
}
void mergesort(int l,int r,vector<pair<int,int>>&arr,vector<int>&ans){

    if(l==r){return;}
    int mid=(l+r)/2;
    mergesort(l,mid,arr,ans);
    mergesort(mid+1,r,arr,ans);
    merge(l,mid,r,arr,ans);
}
    vector<int> countSmaller(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        mergesort(0,n-1,arr,ans);
        return ans;
        
    }
};