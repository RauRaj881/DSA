class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums){
        int n=nums.size();
        vector<int> v(n);
        int k=0,m=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){v[k]=nums[i];k+=2;}
            else if(nums[i]<0){v[m]=nums[i];m+=2;}
        }
        return v;  
    }
};