class Solution {
public:
bool ispossible(int mid,vector<int>& uL){
    int n=uL.size();
    if(n<mid){return false;}
    int cr=mid;
    int gap=0;
    for(int i=0;i<n;i++){
        gap=max(0,cr-uL[i]+gap);
        if(cr>0)cr--;
    }
    return gap==0;
}
    int maxIncreasingGroups(vector<int>& uL){
        int n=uL.size();
        int low=0,high=1e9;
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