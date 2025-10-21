class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=nums[n-1];
        int mn=nums[0];
        vector<int> freqtill(mx+1,0);
        for(int i=0;i<n;i++){
            freqtill[nums[i]]++;
        }
        for(int i=1;i<=mx;i++){
            freqtill[i]+=freqtill[i-1];
        }
        int ans=1;
        for(int i=nums[0];i<=nums[n-1];i++){
            int left=freqtill[max(mn,i-k)-1];
            int right=freqtill[min(mx,i+k)];
            int f=freqtill[i]-freqtill[i-1];
            int p=min(numOperations,right-left-f);
            ans=max(f+p,ans);
        }
        return ans;
    }
};