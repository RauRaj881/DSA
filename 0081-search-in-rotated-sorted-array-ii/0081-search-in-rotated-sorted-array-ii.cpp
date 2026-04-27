class Solution {
public:
    bool search(vector<int>& nums, int tar){
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==tar){return true;}
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            }
            else if(nums[mid]>=nums[low]){
                if(nums[low]<=tar&&nums[mid]>=tar){high=mid-1;}
                else{low=mid+1;}
            }
            else{
                if(nums[mid]<=tar&&nums[high]>=tar){low=mid+1;}
                else{high=mid-1;}
            }
        }
        return false;
        
    }
};