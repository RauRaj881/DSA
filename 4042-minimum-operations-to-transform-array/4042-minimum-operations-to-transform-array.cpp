class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        long long ans=0;
        int last=nums2[n];
        int mn=1e5;
        bool pos=false;
        for(int i=0;i<n;i++){
            ans+=abs(nums1[i]-nums2[i]);
            if((last>=nums1[i]&&last<=nums2[i])||(last<=nums1[i]&&last>=nums2[i])){
                pos=true;
            }
            mn=min(mn,abs(last-nums1[i]));
            mn=min(mn,abs(last-nums2[i]));
        }
        if(pos){ans+=1;}
        else{ans+=mn+1;}
        return ans;
    }
};