class Solution {
public:
bool f(int mid,vector<int>& c,long long k){
    long long cnt=0;
    for(auto it:c){
        cnt+=it/mid;
    }
    return cnt>=k;
}
    int maximumCandies(vector<int>& c,long long k){
        int low=1,high=1e7,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(f(mid,c,k)){ans=mid;low=mid+1;}
            else{high=mid-1;}
        }
        return ans;
    }
};