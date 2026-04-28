class Solution {
public:
bool ispos(int mid,vector<int>& piles, int h){
    long long x=0;
    for(int i=0;i<piles.size();i++){
        x+=(piles[i]+mid-1)/mid;
    }
    return x<=h;
}
    int minEatingSpeed(vector<int>& piles, int h){
        int ans=-1;
        int low=1,high=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispos(mid,piles,h)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};