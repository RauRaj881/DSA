class Solution {
public:
    int trap(vector<int>& h){
        int n=h.size();
        int l=0,r=n-1;
        int leftm=0,rightm=0;
        int ans=0;
        while(l<=r){
            leftm=max(leftm,h[l]);
            rightm=max(rightm,h[r]);
            if(leftm<rightm){ans+=leftm-h[l];l++;}
            else{ans+=rightm-h[r];r--;}
        }
        return ans;
    }
};