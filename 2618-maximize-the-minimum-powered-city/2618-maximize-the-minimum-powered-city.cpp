class Solution {
public:
bool isPossible(long long mid,vector<int> stations,int k, int r){
    int n=stations.size();
    long long winsum=0;
    for(int i=0;i<=r;i++){winsum+=stations[i];}
    if(mid-winsum>k){return 0;}
    else if(winsum<mid){stations[r]+=mid-winsum;k-=mid-winsum;winsum+=mid-winsum;}
    for(int i=1;i<n;i++){
        if(i+r<n){winsum+=stations[i+r];}
        if(i-r-1>=0){winsum-=stations[i-r-1];}
        if(winsum<mid){
        if(mid-winsum>k){return 0;}
        else if(winsum<mid){
            if(i+r<n){stations[i+r]+=mid-winsum;k-=mid-winsum;}
            else{stations[n-1]+=mid-winsum;k-=mid-winsum;}
            winsum+=mid-winsum;
        }
        }
    }
    return 1;
}
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low=0;
        long long high=k;
        for(auto it:stations){high+=it;}
        long long ans;
        while(low<=high){
            long long mid=(low+high)/2;
            if(isPossible(mid,stations,k,r)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};