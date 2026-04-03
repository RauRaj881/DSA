class Solution {
public:
vector<vector<int>> ans;
unordered_set<int> st;
void f(vector<int>& nums,vector<int>& path){
    if(path.size()==nums.size()){ans.push_back(path);return;}
    for(int i=0;i<nums.size();i++){
        if(!st.count(nums[i])){
            st.insert(nums[i]);
            path.push_back(nums[i]);
            f(nums,path);
            path.pop_back();
            st.erase(nums[i]);
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums){
        vector<int> path;
        f(nums,path);
        return ans;
    }
};