class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l=0,h=1e18;
        long long ans;
        long long L=lcm(r[0],r[1]);
        while(l<=h){
            long long mid=(l+h)/2;
            long long a=mid-mid/r[0];
            long long b=mid-mid/r[1];
            if(a>=d[0]&&b>=d[1]&&d[0]+d[1]<=mid-mid/L){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};