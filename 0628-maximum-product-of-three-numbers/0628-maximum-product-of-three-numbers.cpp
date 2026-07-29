class Solution {
public:
    int maximumProduct(vector<int>& nums){
        int n=nums.size();
        int mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        int mn1=INT_MAX,mn2=INT_MAX;
        for(auto it:nums){
            if(it>mx1){mx3=mx2;mx2=mx1;mx1=it;}
            else if(it>mx2){mx3=mx2;mx2=it;}
            else if(it>mx3){mx3=it;}

            if(it<mn1){mn2=mn1;mn1=it;}
            else if(it<mn2){mn2=it;}
        }

        return max(mx1*mx2*mx3,mx1*mn1*mn2);
    }
};