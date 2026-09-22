class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size()<nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int tot=n1+n2;
        int lthf=(n1+n2)/2;
        int low=max(0,lthf-n2);
        int high=min(n1,lthf);
        while(low<=high){
            int mid=(low+high)/2;
            int rem=lthf-mid;
            int mx1=(mid>0)?nums1[mid-1]:INT_MIN;
            int mx2=(rem>0)?nums2[rem-1]:INT_MIN;
            int mn1=(mid<n1)?nums1[mid]:INT_MAX;
            int mn2=(rem<n2)?nums2[rem]:INT_MAX;
            if(mx1>mn2){
                high=mid-1;
            }
            else if(mx2>mn1){
                low=mid+1;
            }
            else{
                if(tot%2==1){
                    return min(mn1,mn2);
                }
                else{
                    return (max(mx1,mx2)+min(mn1,mn2))/2.0;
                }
            }
        }
        return 0.0;
        
    }
};