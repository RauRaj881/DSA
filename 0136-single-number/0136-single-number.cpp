/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=0,p;
        for(int i=1;i<n-1;i+=2){
            if(nums[i]==nums[i-1]) {s++;continue;}
            else if(nums[i]!=nums[i-1]) {p=nums[i-1]; break;}
        }
        if(s==(n-1)/2){p=nums[n-1];}
        return p;
    }
};*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto it:nums){
            x=x^it;
        }
        return x;
    }
};