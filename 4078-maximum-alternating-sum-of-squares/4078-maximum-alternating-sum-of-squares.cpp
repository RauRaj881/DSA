class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]*=-1;
            }
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int g=(n+1)/2;
        int cnt=0;
        int idx=0;
        for(int i=n-1;i>=0;i--){
            ans+=nums[i]*nums[i];
            cnt++;
            if(cnt==g){idx=i;break;}
        }
        for(int j=idx-1;j>=0;j--){
            ans-=nums[j]*nums[j];
        }
        return ans;
    }
};