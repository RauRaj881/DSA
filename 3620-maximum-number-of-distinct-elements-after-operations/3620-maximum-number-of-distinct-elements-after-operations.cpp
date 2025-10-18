class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int prev=nums[0]-k;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]+k>=prev+1&&nums[i]-k<=prev+1){
                prev++;
                cnt++;
            }
            else if(nums[i]-k>prev+1){prev=nums[i]-k;cnt++;}
            //else if(nums[i]+k>prev+1)
        }
        return cnt;
    }
};