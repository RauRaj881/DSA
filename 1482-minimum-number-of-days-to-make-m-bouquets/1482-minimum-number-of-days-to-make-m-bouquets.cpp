class Solution {
public:
bool f(int mid,int m,int k,vector<int>& bday){
    int n=bday.size();
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(bday[i]<=mid){cnt++;if(cnt==k){ans++;cnt=0;}}
        else{cnt=0;}
    }
    return ans>=m;
}
    int minDays(vector<int>& bday,int m,int k){
        int n=bday.size();
        if(1LL*n<1LL*m*k){return -1;}
        int low=1;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,m,k,bday)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};