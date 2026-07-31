class Solution {
public:
    int findTargetSumWays(vector<int>& nums,int tar){
        int n=nums.size();
        int sum=0;
        for(auto it:nums){sum+=it;}
        if((tar+sum)%2!=0||abs(tar)>sum){return 0;}
        int trg=(tar+sum)/2;
        vector<int> prv(trg+1,0);
        prv[0]=1;
        if(nums[0]<=trg){prv[nums[0]]++;}
        for(int i=1;i<n;i++){
            vector<int> cur(trg+1,0);
            for(int j=0;j<=trg;j++){
                int nt=prv[j];
                int t=0;
                if(nums[i]<=j){t=prv[j-nums[i]];}
                cur[j]=nt+t;
            }
            prv=cur;
        }
        return prv[trg];
    }
};