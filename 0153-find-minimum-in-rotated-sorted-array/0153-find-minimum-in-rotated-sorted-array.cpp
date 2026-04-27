/*class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=6000;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){ans=min(ans,nums[low]);break;}
            else if(nums[mid]>=nums[low]){ans=min(nums[low],ans);low=mid+1;}
            else if(nums[low]>=nums[mid]){ans=min(nums[mid],ans);high=mid-1;}
        }
        return ans;
    }
};*/
class Solution {
public:
    int findMin(vector<int>& nums) {
           int n=nums.size();
        int ans=6000;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>=nums[low]){ans=min(nums[low],ans);low=mid+1;}
            else{ans=min(nums[mid],ans);high=mid-1;}
        }
        return ans;
    }
};