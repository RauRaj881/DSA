class Solution {
public:
    int mySqrt(int x){
        long long low=1,high=x;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(1LL*mid*mid<=x){ans=mid;low=mid+1;}
            else{high=mid-1;}
        }
        return ans;
    }
};