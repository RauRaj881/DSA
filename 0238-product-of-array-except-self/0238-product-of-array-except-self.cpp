/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> preprod(n);
        vector<int> sufprod(n);
        int prod1=1,prod2=1;
        for(int i=0;i<n;i++){
            prod1=prod1*nums[i];
            prod2=prod2*nums[n-i-1];
            preprod[i]=prod1;
            sufprod[n-i-1]=prod2;
        }
        for(int i=0;i<n;i++){
            if(i==0){nums[i]=sufprod[1];}
            else if(i==n-1){nums[i]=preprod[n-2];}
            else{nums[i]=preprod[i-1]*sufprod[i+1];}
        }
        return nums;
    }
};*/
//O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod1=1,prod2=1;
        vector<int> ans(n);
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