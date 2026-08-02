class Solution {
public:
bool f(int mid,vector<int>&q,int n){
    int tot=0;
    for(int i=0;i<q.size();i++){
        tot+=(q[i]+mid-1)/mid;
    }
    return tot<=n;
}
    int minimizedMaximum(int n, vector<int>& q){
        int high=1e6,low=1,ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,q,n)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};