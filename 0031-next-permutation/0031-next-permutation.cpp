class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),r=0,p;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){p=i;break;}
            else{r++;continue;}
        }
        if(r==n-1){reverse(nums.begin(),nums.end());}
        else{
            for(int j=n-1;j>p;j--){
                if(nums[j]>nums[p]){swap(nums[j],nums[p]);break;}
            }
            reverse(nums.begin()+p+1,nums.end());
        }
        return;
    }
};