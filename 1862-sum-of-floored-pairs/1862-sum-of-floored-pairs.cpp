class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }
        vector<int> freq(mx+1,0);
        vector<int> pre(mx+1,0);
        for(int i=0;i<n;i++){
            pre[nums[i]]++;
            freq[nums[i]]++;
        }
        for(int i=1;i<=mx;i++){
            pre[i]+=pre[i-1];
        }
        int ans=0;
        int mod=1e9+7;
        for(int i=1;i<=mx;i++){
            if(freq[i]==0){continue;}
            int div=1;
            int num=i;
            while(div*num<=mx){
                int r=min(mx,((div+1)*num-1));
                int l=div*num;
                
                ans=(ans+(long long)(pre[r]-pre[l-1])*div*freq[i])%(mod);
                div++;
            }
        }
        return ans;
    }
};