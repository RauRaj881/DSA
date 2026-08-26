class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int cr=1;
            for(int j=i;j<n;j++){
                cr*=nums[j];
                if(cr<k){cnt++;}
                else{break;}
            }
        }
        return cnt;
    }
};