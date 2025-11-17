class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt=0;
        bool first=false;
        for(auto it:nums){
            if(it==1&&first==false){first=true;continue;}
            if(it==1&&cnt>=k){cnt=0;}
            else if(it==1&&cnt<k&&first){return 0;}
            else if(it==0&&first){cnt++;}
        }
        return 1;
    }
};