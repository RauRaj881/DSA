class Solution {
public:
    int searchInsert(vector<int>& nums, int tar){
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==tar){return mid;}
            else if(nums[mid]>tar){high=mid-1;}
            else{low=mid+1;}
        }
        return low;
    }
};