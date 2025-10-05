class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){zero++;}
            x=x^nums[i];
        }
        if(x!=0){return nums.size();}
        else if(zero==nums.size()){return 0;}
        return nums.size()-1;
    }
};