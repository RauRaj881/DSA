class Solution {
public:
    int search(vector<int>& nums, int tar){
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==tar){return mid;}
            if(nums[low]<=nums[mid]){
                if(tar>=nums[low]&&tar<=nums[mid]){high=mid;}
                else{low=mid+1;}
            }
            else{
                if(nums[mid]<=tar&&nums[high]>=tar){low=mid+1;}
                else{high=mid-1;}
            }
        }
        return -1;
    }
};