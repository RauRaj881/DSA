class Solution{
    public:
    bool f(int mid,int m,int k,vector<int>& bd){
        int cnt=0;
        int cnt2=0;
        for(int i=0;i<bd.size();i++){
            if(bd[i]<=mid){cnt++;}
            else{cnt=0;}
            if(cnt==k){cnt2++;cnt=0;}
        }
        return cnt2>=m;
    }
    int minDays(vector<int>& bd,int m,int k){
        int n=bd.size();
        int low=1,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid,m,k,bd)){ans=mid;high=mid-1;}
            else{
                low=mid+1;
            }
        }
        return ans;


    }
};