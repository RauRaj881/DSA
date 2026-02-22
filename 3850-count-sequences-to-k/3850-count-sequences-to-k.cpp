class Solution {
public:
tuple<int,int,int> fact(long long n){
    int cnt2=0,cnt3=0,cnt5=0;
    while(n%2==0){cnt2++;n/=2;}
    while(n%3==0){cnt3++;n/=3;}
    while(n%5==0){cnt5++;n/=5;}
    return {cnt2,cnt3,cnt5};
}
    int countSequences(vector<int>& nums, long long k){
        int n=nums.size();
        map<tuple<int,int,int>,int> dp;
        dp[{0,0,0}]=1;
        for(int i=0;i<n;i++){
            auto [a,b,c]=fact(nums[i]);
            map<tuple<int,int,int>,int> ndp;
            for(auto it:dp){
                auto [x,y,z]=it.first;
                int cnt=it.second;
                ndp[{x+a,y+b,z+c}]+=cnt;
                ndp[{x-a,y-b,z-c}]+=cnt;
                ndp[{x,y,z}]+=cnt;
            }
            dp=ndp;
        }
        long long ori=k;
        int c2=0,c3=0,c5=0;
        while(k%2==0){c2++;k/=2;}
        while(k%3==0){c3++;k/=3;}
        while(k%5==0){c5++;k/=5;}
        if(k!=1){return 0;}
        return dp[fact(ori)];
    }
};