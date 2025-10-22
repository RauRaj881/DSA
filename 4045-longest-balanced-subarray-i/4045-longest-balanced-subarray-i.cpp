class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            int diseven=0,disodd=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0&&!mp.count(nums[j])){
                    diseven++;
                    mp[nums[j]]++;
                }
                else if(nums[j]%2!=0&&!mp.count(nums[j])){
                    disodd++;
                    mp[nums[j]]++;
                }
                if(diseven==disodd){ans=max(ans,j-i+1);}
            }
        }
        return ans;
    }
};