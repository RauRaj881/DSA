class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        int mx1=-1,mx2=-1;
        for(auto it:nums){if(it>mx1){mx2=mx1;mx1=it;}else if(it>mx2){mx2=it;}}
        return (mx1-1)*(mx2-1);
        
    }
};