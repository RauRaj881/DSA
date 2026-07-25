class Solution {
public:
void f(int sm,int l,int r,vector<int>& lt,vector<int>& nums){
    if(l>r){lt.push_back(sm);return;}
    f(sm,l+1,r,lt,nums);
    f(sm+nums[l],l+1,r,lt,nums);
}
    int minAbsDifference(vector<int>& nums, int goal){
        int n=nums.size();
        int tot=0;
        for(auto it:nums){tot+=it;}
        vector<int> lt;
        vector<int> rt;
        f(0,0,n/2,lt,nums);
        f(0,n/2+1,n-1,rt,nums);
        //for(int i=0;i<=n/2;i++){
            sort(rt.begin(),rt.end());
        //}
        int mn=INT_MAX;
            for(auto it:lt){
                auto it2=lower_bound(rt.begin(),rt.end(),(goal-it));
                if(it2!=rt.end()){
                    int idx=it2-rt.begin();
                    int sm1=it,sm2=rt[idx];
                    int sb1=sm1+sm2;
                    mn=min(mn,abs(sb1-goal));
                }
                if(it2!=rt.begin()){
                    int idx=it2-rt.begin()-1;
                    int sm1=it,sm2=rt[idx];
                    int sb1=sm1+sm2;
                    mn=min(mn,abs(sb1-goal));
                }
            }
        return mn;
    }
};