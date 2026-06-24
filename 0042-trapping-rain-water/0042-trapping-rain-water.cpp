class Solution {
public:
    int trap(vector<int>& hgt){
        int n=hgt.size();
        int leftm=-1,rightm=-1;
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            leftm=max(leftm,hgt[l]);
            rightm=max(rightm,hgt[r]);
            if(leftm<rightm){ans+=leftm-hgt[l];l++;}
            else{ans+=rightm-hgt[r];r--;}
        }
        return ans;
    }
};