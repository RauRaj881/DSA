class Solution {
public:
bool sorted(vector<int>&nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1]){return false;}
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(!sorted(nums)){
            int n=nums.size();
            int mn=INT_MAX;
            int idx=-1;
            for(int i=0;i<n-1;i++){
                int curr=nums[i]+nums[i+1];
                if(curr<mn){idx=i;mn=curr;}
            }
            ans++;
            nums[idx]=mn;
            nums.erase(nums.begin()+idx+1);
        }
        return ans;
    }
};