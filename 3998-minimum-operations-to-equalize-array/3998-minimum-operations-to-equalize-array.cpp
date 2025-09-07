class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==x){cnt++;}
        }
        if(cnt==n){return 0;}
        return 1;
    }
};