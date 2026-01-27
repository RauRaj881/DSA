class Solution {
public:
        int maxFrequency(vector<int>& nums, int k, int np) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            map<int,int> mp;
            unordered_map<int,int> mp2;
            for(int i=0;i<n;i++){
                int num=nums[i];
                mp[num-k]++;
                mp[num+k+1]--;
                mp[nums[i]]+=0;
                mp2[nums[i]]++;
            }
            int cumsum=0;
            for(auto it:mp){
                int num=it.first;
                int freq=it.second;
                cumsum+=freq;
                mp[num]=cumsum;
            }
            int ans=0;
            for(auto it:mp){
                int num=it.first;
                int freq=it.second;
                int ald=mp2[num];
                int rem=freq-ald;
                int bna=min(rem,np);
                ans=max(ans,bna+ald);
            }
            return ans;
    }
};