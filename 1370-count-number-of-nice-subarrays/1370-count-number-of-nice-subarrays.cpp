/*class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){nums[i]=1;}
            else{nums[i]=0;}
        }
        return fn(nums,k)-fn(nums,k-1);
    }
        int fn(vector<int>& nums, int k){
            int h=0,sum=0,left=0,right=0;
            while(right!=nums.size()){
                sum+=nums[right];
                while(sum>k){
                    sum-=nums[left];
                    left++;
                }
                h+=right+1-left;//no. of subarray ending at right is equal to right+1-left;
                right++;
            }
            return h;
        }
};*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=(nums[0]%2!=0 ? 1:0);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(nums[i]%2!=0 ? 1:0);
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=prefix[i];
            if(mp.find(x-k)!=mp.end()){
                cnt+=mp[x-k];
            }
            mp[x]++;
        }
        return cnt;
    }
};