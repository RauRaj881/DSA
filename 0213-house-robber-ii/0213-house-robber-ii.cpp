class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev=0;
        int n=nums.size();
        int curr;
        if(n==1){return nums[0];}
        for(int i=0;i<n-1;i++){
            int pick=nums[i];
            if(i>1){pick+=prev2;}
            int notpick=0;
            if(i>0){notpick+=prev;}
            curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        int pre2=0;
        int pre=0;
        int curr2;
        for(int i=1;i<n;i++){
            int pick2=nums[i];
            if(i>2){pick2+=pre2;}
            int notpick2=0;
            if(i>1){notpick2+=pre;}
            curr2=max(pick2,notpick2);
            pre2=pre;
            pre=curr2;
        }
        return max(curr,curr2);
    }
};