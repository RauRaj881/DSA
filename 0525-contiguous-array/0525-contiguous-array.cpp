class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> presum(n);
        presum[0]=(nums[0]==1 ? 1:-1);
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+(nums[i]==1 ? 1:-1);
        }
        if(presum[n-1]==0){return n;}
        map<int,int> mp;
        mp[0]=-1;
        int maxlength=0;
        for(int i=0;i<n;i++){
            int x=presum[i];
            if(mp.find(x)==mp.end()){
                mp[x]=i;
            }
            else{
                maxlength=max((i-mp[x]),maxlength);
                //mp[x]=i;
            }
        }
        return maxlength;
    }
};