class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]){continue;}
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]){continue;}
                long long x=1LL*tar-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    long long tp=nums[l]+nums[r];
                    if(tp==x){ans.push_back({nums[i],nums[j],nums[l],nums[r]});l++;r--;}
                    else if(tp>x){r--;}
                    else{l++;}
                    while(l>j+1&&l<n&&nums[l]==nums[l-1]){l++;}
                    while(r<n-1&&r>j&&nums[r]==nums[r+1]){r--;}
                }
            }
        }
        return ans;
    }
};