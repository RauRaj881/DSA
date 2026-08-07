class Solution {
public:
bool f(int mid,vector<int>& piles, int h){
    long long cnt=0;
    for(auto it:piles){
        cnt+=(it+mid-1)/mid;
    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h){
        int mx=0;
        for(auto it:piles){mx=max(mx,it);}
        int low=1,high=mx;
        int ans=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(f(mid,piles,h)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;     
    }
};