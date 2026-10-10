class Solution {
public:
bool f(int mid,vector<int>& w,int d){
    int cnt=0;
    int sm=0;
    for(auto it:w){
        if(it>mid){return false;}
        sm+=it;
        if(sm>mid){cnt++;sm=it;}
    }
    cnt++;
    return cnt<=d;
}
    int shipWithinDays(vector<int>& w,int d){
        int n=w.size();
        int low=1,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,w,d)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};