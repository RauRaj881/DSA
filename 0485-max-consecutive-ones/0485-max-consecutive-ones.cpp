class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int cnt=0,mx=0;
        for(auto it:nums){
            if(it==1){cnt++;}
            else{mx=max(mx,cnt);cnt=0;}
        }
        mx=max(mx,cnt);
        return mx;
    }
};