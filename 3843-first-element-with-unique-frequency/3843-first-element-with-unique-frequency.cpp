class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto it:nums){
            int x=mp1[it];
            if(x>0){
                mp2[x]--;
            }
            mp2[x+1]++;
            mp1[it]++;
        }
        for(int i=0;i<n;i++){
            if(mp2[mp1[nums[i]]]==1){return nums[i];}
        }
        return -1;
    }
};