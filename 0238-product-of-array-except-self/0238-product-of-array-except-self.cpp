class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n);
        int prod1=1;
        int prod2=1;
        for(int i=0;i<n;i++){
            ans[i]=prod1;
            prod1*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=prod2;
            prod2*=nums[i];
        }
        return ans;
    }
};