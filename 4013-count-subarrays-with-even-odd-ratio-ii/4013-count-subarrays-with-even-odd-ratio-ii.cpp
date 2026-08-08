#define ll long long
class Solution {
public:
ll ans=0;
void merge(vector<ll>&pre,int l,int mid,int r){
    vector<ll> tp;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(pre[i]>=pre[j]){ans+=mid-i+1;tp.push_back(pre[j]);j++;}
        else{tp.push_back(pre[i]);i++;}
    }
    while(i<=mid){tp.push_back(pre[i]);i++;}
    while(j<=r){tp.push_back(pre[j]);j++;}
    for(int i=0;i<tp.size();i++){
        pre[i+l]=tp[i];
    }
}
void mergesort(vector<ll>&pre,int l,int r){
    if(l==r){return;}
    int mid=(l+r)/2;
    mergesort(pre,l,mid);
    mergesort(pre,mid+1,r);
    merge(pre,l,mid,r);
}

    long long countRatioSubarrays(vector<int>& nums, int a, int b){
        int n=nums.size();
        vector<ll> pre(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                pre[i+1]=pre[i]+b;
            }
            else{
                pre[i+1]=pre[i]-a;
            }
        }
        mergesort(pre,0,n);
        return ans;
    }
};