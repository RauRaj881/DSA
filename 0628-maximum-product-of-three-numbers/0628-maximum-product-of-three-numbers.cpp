class Solution {
public:
    int maximumProduct(vector<int>& nums){
        int n=nums.size();
        if(n==3){return nums[n-1]*nums[n-2]*nums[n-3];}
        vector<int> neg;
        vector<int> pos;
        for(auto it:nums){if(it<=0){neg.push_back(it);}else{pos.push_back(it);}}
        sort(neg.begin(),neg.end());
        sort(pos.begin(),pos.end());
        int sz1=neg.size(),sz2=pos.size();
        if(neg.size()<=1){return pos[sz2-1]*pos[sz2-2]*pos[sz2-3];}
        if(pos.size()==0){return neg[sz1-1]*neg[sz1-2]*neg[sz1-3];}
        int mx1=neg[0]*neg[1];
        int mx2=-1;
        if(pos.size()>=3){mx2=pos[sz2-2]*pos[sz2-3];}
        return max(mx1,mx2)*pos[sz2-1];
    }
};