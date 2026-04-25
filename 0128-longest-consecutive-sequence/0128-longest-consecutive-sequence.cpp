class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int y=1;
        int maxno=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){y++;}
            else if(nums[i]==nums[i-1]){y=y;}
            else {y=1;}
            maxno=max(maxno,y);
        }
        if(nums.size()==1){maxno=1;}
        return maxno;
    }
};