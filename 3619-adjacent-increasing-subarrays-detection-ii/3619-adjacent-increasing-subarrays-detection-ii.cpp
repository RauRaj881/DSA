//O(n) space
/*
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        vector<int> presum(n);
        presum[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                ans=max(ans,cnt/2);
                }
                else{cnt=1;}
                if((i-cnt)>=0&&presum[i-cnt]>=cnt){
                    ans=max(ans,cnt);
                }
                presum[i]=cnt;
        }
        return ans;
    }
};*/
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int precnt=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                ans=max(ans,cnt/2);
                }
                else{precnt=cnt;cnt=1;}
                ans=max(ans,min(cnt,precnt));
        }
        return ans;
    }
};