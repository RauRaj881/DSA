class Solution {
public:
vector<vector<int>> ans;
void f(int i,int n,vector<int>&nums){
    if(i==n){ans.push_back(nums);return;}
    for(int idx=i;idx<n;idx++){
        swap(nums[i],nums[idx]);
        f(i+1,n,nums);
        swap(nums[i],nums[idx]);
    }
}
    vector<vector<int>> permute(vector<int>& nums){
        int n=nums.size();
        f(0,n,nums);
        return ans;
    }
};