class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        //stack<int> st;
        long long sum1=nums[0];
        int ind1=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){sum1+=nums[i];ind1=i;}
            else{break;}
        }
        long long sum2=nums[n-1];
        int ind2=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){sum2+=nums[i];ind2=i;}
            else{break;}
        }
        if(ind1==ind2){
            return min(abs((sum1-nums[ind2])-sum2),abs(sum1-(sum2-nums[ind2])));}
        else if((ind1+1==ind2)&&nums[ind1]==nums[ind2]){return abs(sum1-sum2);}
        return -1;
    }
};