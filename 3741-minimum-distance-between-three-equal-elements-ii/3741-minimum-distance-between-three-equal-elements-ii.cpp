class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> lastidx(n+1,vector<int>(2,-1));
        int ans=1e9;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(lastidx[x][0]==-1){lastidx[x][0]=i;}
            else if(lastidx[x][1]==-1){lastidx[x][1]=i;}
            else{ans=min(ans,2*abs(i-lastidx[x][0]));lastidx[x][0]=lastidx[x][1];lastidx[x][1]=i;}
        }
        if(ans==1e9){ans=-1;}
        return ans;
    }
};