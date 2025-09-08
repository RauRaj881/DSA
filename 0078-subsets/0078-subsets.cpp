//using recursion
/*class Solution {
public:
    void backtrack(vector<vector<int>> &v,  vector<int> &ans, vector<int> nums,int i){
        if(i==nums.size()){v.push_back(ans);return;}
        ans.push_back(nums[i]);
        backtrack(v,ans,nums,i+1);
        ans.pop_back();
        backtrack(v,ans,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        backtrack(v,ans,nums,0);
        return v;
    }
};*/
//using power set technique
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int totss=1<<n;
        vector<vector<int>> v;
        for(int num=0;num<totss;num++){
            vector<int> ans;
            for(int i=0;i<n;i++){
                if((num&(1<<i))!=0){
                    ans.push_back(nums[i]);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};