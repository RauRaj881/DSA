class Solution {
public:
bool f(int mid,vector<int>& v,vector<int>& d, int m){
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]<mid){continue;}
        cnt+=(v[i]-mid)/d[i]+1;
        if (cnt >= m) return true;
    }
    return cnt>=m;
}
    int maxTotalValue(vector<int>& v,vector<int>& d,int m){
        long long mod=1e9+7;
        int n=v.size();
        int tp=0;
        //for(auto it:v){tp+=it;}
        int low=1,high=1e9;
        int mnvl=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,v,d,m)){mnvl=mid;low=mid+1;}
            else{high=mid-1;}
        }
        //if(mnvl==-1){return tp;}
        long long ans=0;
        int tot=0;
        for(int i=0;i<n;i++){
            if(v[i] <= mnvl){continue;}
            int st=mnvl+1;
            int k=(v[i]-st)/d[i]+1;
            int a=v[i];
            int l=a-(k-1)*d[i];
            long long sm=(long long)(k)*(a+l)/2;
            ans=(ans+sm)%(mod);
            tot+=k;
        }
        int rem=m-tot;
        ans=(ans+(long long)mnvl*rem)%(mod);
        return ans;
    }
};