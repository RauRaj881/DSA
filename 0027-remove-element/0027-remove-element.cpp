class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int idx=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                cnt++;
                nums[idx]=nums[i];
                idx++;
            }
        }
        return cnt;
    }
};