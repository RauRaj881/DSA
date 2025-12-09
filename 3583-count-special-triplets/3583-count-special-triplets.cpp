class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        unordered_map<int,int> mp1;
        mp1[nums[0]]++;
        vector<long long> freqPrev(n);
        freqPrev[0]=0;
        for(int i=1;i<n;i++){
            int num=nums[i];
            freqPrev[i]=mp1[2*num];
            mp1[nums[i]]++;
        }
        unordered_map<int,int> mp2;
        mp2[nums[n-1]]++;
        vector<long long> freqNext(n);
        freqNext[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int num2=nums[i];
            freqNext[i]=mp2[2*num2];
            mp2[nums[i]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long x=freqPrev[i]*freqNext[i];
            ans=(ans+x)%(mod);
        }
        return ans;
    }
};