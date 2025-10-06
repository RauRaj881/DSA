/*class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0,h=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                h+=mp[sum-goal];
            }
        mp[sum]++;
        }
        return h;
    }
};*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=presum[i];
            if(mp.find(x-k)!=mp.end()){
                cnt+=mp[x-k];
            }
            mp[x]++;
        }
        return cnt;
    }
};