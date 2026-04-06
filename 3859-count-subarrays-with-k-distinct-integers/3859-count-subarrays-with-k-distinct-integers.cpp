class Solution {
public:
    long long countSubarrays(vector<int>& nums,int k,int m){
        int n=nums.size();
        int l1=0,l2=0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int tv=0;
        long long ans=0;
        for(int r=0;r<n;r++){
            mp1[nums[r]]++;
            mp2[nums[r]]++;
            if(mp2[nums[r]]==m){tv++;}
            while(mp1.size()>k&&l1<r){
                mp1[nums[l1]]--;
                if(mp1[nums[l1]]==0){mp1.erase(nums[l1]);}
                l1++;
            }
            while(tv>=k){
                mp2[nums[l2]]--;
                if(mp2[nums[l2]]==m-1){tv--;}
                l2++;
            }
            if(l1<l2){ans+=(l2-l1);}
        }
        return ans;
        
    }
};