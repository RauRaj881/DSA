class Solution {
public:
int cnt=0;
void f(int i,int sm,vector<int>& nums, int tar){
    if(i==nums.size()){if(sm==tar){cnt++;}return;}
    f(i+1,sm+nums[i],nums,tar);
    f(i+1,sm-nums[i],nums,tar);
}
    int findTargetSumWays(vector<int>& nums, int tar){
        f(0,0,nums,tar);
        return cnt;
    }
};