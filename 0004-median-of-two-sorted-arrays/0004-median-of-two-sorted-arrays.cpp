class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> v;
        for(auto it:nums1){v.push_back(it);}
        for(auto it:nums2){v.push_back(it);}
        sort(v.begin(),v.end());
        if((n1+n2)%2==1){return v[(n1+n2)/2];}
        double ans=(v[(n1+n2)/2]+v[(n1+n2)/2-1])/2.0;
        return ans;
    }
};