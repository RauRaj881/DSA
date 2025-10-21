//TLE O(N^2*LOG(N))
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            unordered_map<int,int> mp;
            mp[nums[i]]=i;
            for(int j=i+1;j<n;j++){
                if(mp.count(target-nums[j])&&mp[target-nums[j]]!=i){
                    vector<int> temp={nums[i],nums[j],nums[mp[target-nums[j]]]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]=j;
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};*/
//USING 2 POINTERS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            int target=-nums[i];
            while(j<k){
                if(nums[j]+nums[k]==target){
                    if(!st.count({nums[i],nums[j],nums[k]})){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        st.insert({nums[i],nums[j],nums[k]});
                    }
                    else{
                        j++;k--;
                    }
                }
                else if(nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};