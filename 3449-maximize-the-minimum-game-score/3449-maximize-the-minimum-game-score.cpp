class Solution {
public:
bool ispossible(long long mid,vector<int>& points,long long m){
    int n=points.size();
    long long cnt=0;
    long long prev=0;
    for(int i=0;i<n;i++){
        int x=points[i];
        long long rq=(mid+x-1)/x;
        if(i<n-1){
            if(prev>=rq){
                prev=0;
                cnt+=1;
            }
            else{
                cnt+=2*(rq-prev)-1;
                prev=(rq-prev)-1;
            }
        }
        else{
            if(prev<rq){
                cnt+=2*(rq-prev)-1;
            }
        }
        if(cnt>m){return false;}
    }
    return cnt<=m;
}
    long long maxScore(vector<int>& points, int m) {
        long long n=points.size();
        int mn=1e7,mx=0;
        for(int i=0;i<n;i++){
            mn=min(mn,points[i]);
            mx=max(mx,points[i]);
        }
        long long low=mn,high=(long long)mx*m;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,points,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};