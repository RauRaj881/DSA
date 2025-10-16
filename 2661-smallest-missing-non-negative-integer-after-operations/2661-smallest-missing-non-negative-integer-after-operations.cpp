class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            nums[i]=(nums[i]%value+value)%value;
            mp[nums[i]]++;
        }
        for(int i=0;i<=n;i++){
            if(mp[i%value]>0){mp[i%value]--;}
            else{return i;}
        }
        return n;
    }
};