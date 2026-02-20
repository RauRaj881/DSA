class Solution {
public:
bool ispossible(int mid,vector<int>& uL){
    int n=uL.size();
    if(n<mid){return false;}
    int req=mid;
    int gap=0;
    for(int i=0;i<n;i++){
        gap=max(0,req-uL[i]+gap);
        if(req>0)req--;
    }
    return gap==0;
}
    int maxIncreasingGroups(vector<int>& uL){
        int n=uL.size();
        int low=0,high=n;
        int ans=0;
        sort(uL.begin(),uL.end(),greater<int>());
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(mid,uL)){
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