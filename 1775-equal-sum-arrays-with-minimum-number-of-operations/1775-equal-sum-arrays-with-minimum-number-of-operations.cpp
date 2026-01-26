class Solution {
public:
int solve(vector<int>& nums1, vector<int>& nums2,int s1,int s2){
    int n1=nums1.size();
    int n2=nums2.size();
    int i1=n1-1;
    int i2=0;
    int tot=0;
    while(i1>=0||i2<n2){
        if(s1<=s2){break;}
        if(i1<0){
            s2+=6-nums2[i2];
            i2++;
        }
        else if(i2>=n2){
            s1-=nums1[i1];
            s1+=1;
            i1--;
        }
        else{
        if(nums1[i1]-1>=6-nums2[i2]){
            s1-=nums1[i1];
            s1+=1;
            i1--;
        }
        else{
            s2+=6-nums2[i2];
            i2++;
        }
        }
        tot++;
    }
    return tot;
}
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int s1=0,s2=0;
        for(auto it:nums1){s1+=it;}
        for(auto it:nums2){s2+=it;}
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(s1==s2){return 0;}
        else if(s1>s2){
            if(n2*6<n1){return -1;}
            return solve(nums1,nums2,s1,s2);
        }
        if(n1*6<n2){return -1;}
        return solve(nums2,nums1,s2,s1);
    }
};