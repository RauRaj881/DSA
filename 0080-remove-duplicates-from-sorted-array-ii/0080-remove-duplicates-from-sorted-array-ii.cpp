class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        int cnt=1;
        int ans=0;
        if(n==1){return 1;}
        nums[idx]=nums[0];
        idx++;
        ans++;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{cnt=1;}
            if(cnt<=2){
                nums[idx]=nums[i];
                idx++;
                ans++;
            }
        }
        return ans;
    }
};