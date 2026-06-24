class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftm=-1,rightm=-1;
        int l=0,r=n-1,total=0;
        while(l<r){
            leftm=max(height[l],leftm);
            rightm=max(height[r],rightm);
            if(leftm<=rightm){total+=leftm-height[l];l++;}
            else{total+=rightm-height[r];r--;}
        }
        return total;
    }
};