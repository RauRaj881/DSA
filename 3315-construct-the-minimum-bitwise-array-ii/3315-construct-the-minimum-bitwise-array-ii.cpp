class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num==2){nums[i]=-1;continue;}
            int x=1;
            while((num&x)!=0){
                x<<=1;
            }
            num^=(x>>1);
            nums[i]=num;
        }
        return nums;
    }
};