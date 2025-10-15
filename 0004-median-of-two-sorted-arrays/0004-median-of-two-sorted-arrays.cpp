class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans(m+n);
        for(int k=0;k<m+n;k++){
            if(i==m){ans[k]=nums2[j];j++;}
            else if(j==n){ans[k]=nums1[i];i++;}
            else if(nums1[i]<nums2[j]){ans[k]=nums1[i];i++;}
            else{ans[k]=nums2[j];j++;}
        }
        double x;
        if((m+n)%2!=0){x=ans[(m+n)/2];return x;}
        else{x=(ans[(m+n)/2-1]+ans[(m+n)/2])/2.0;return x;}
    }
};