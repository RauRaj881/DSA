class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int mx=0;
        for(auto it:mp){
            int cr=it.first;
            if(!mp.count(cr-1)){
                int len=0;
                while(mp.count(cr)){
                    len++;
                    cr++;
                }
                mx=max(mx,len);
            }
        }
        return mx;
    }
};