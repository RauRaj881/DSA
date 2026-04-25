class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar){
        int n=nums.size();
        if(n==0){return {-1,-1};}
        int low=0,high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>=tar){high=mid;}
            else{low=mid+1;}
        }
        int lt=-3;
        if(nums[low]!=tar){return {-1,-1};}
        else{lt=low;}
        low=0,high=n-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if(nums[mid]<=tar){low=mid;}
            else{high=mid-1;}
        }
        return {lt,low};
    }
};