using ll = long long;
class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long> sumtill(n);
        sort(nums.begin(),nums.end());
        sumtill[0]=nums[0];
        for(int i=1;i<n;i++){
            sumtill[i]=nums[i]+sumtill[i-1];
        }
        int l=0,r=0;
        int ans=0;
        while(r<n){
            long long diff=(ll)(r-l+1)*nums[r]-(sumtill[r]-(l>0?sumtill[l-1]:0));
            if(diff<=k){
                ans=max(ans,r-l+1);
                r++;
            }
            else{l++;}
        }
        return ans;
    }
};