class Solution {
public:
vector<vector<int>> ans;
void f(int i,int k,int n,vector<int>& nums,vector<int>& tp,int sm){
    if(i==nums.size()){if(tp.size()==k&&sm==n){ans.push_back(tp);}return;}
    tp.push_back(nums[i]);
    f(i+1,k,n,nums,tp,sm+nums[i]);
    tp.pop_back();
    f(i+1,k,n,nums,tp,sm);
}
    vector<vector<int>> combinationSum3(int k, int n){
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> tp;
        f(0,k,n,nums,tp,0);
        return ans;
    }
};