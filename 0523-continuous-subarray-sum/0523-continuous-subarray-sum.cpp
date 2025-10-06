class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int cnt=0;
        bool pos=false;
        for(int i=0;i<n;i++){
            int x=presum[i];
            if(mp.find(x%k)==mp.end()){mp[x%k]=i;}
            else if(mp.find(x%k)!=mp.end()&&(i-mp[x%k]>=2)){
                pos=true;break;
            }
        }
        return pos;
    }
};