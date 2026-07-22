class Solution {
public:
    int jump(vector<int>& nums){
        int n=nums.size();
        int cnt=0;
        int mx=0;
        int tp=0;
        for(int i=0;i<n-1;i++){
            int cr=i+nums[i];
            tp=max(tp,cr);
            if(i==mx){mx=tp;cnt++;}
        }
        return cnt;
    }
};