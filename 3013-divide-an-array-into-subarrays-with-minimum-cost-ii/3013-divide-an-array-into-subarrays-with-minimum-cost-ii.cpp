class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        multiset<int> sm,lg;
        //long long ans=nums[0];
        k--;
        for(int i=1;i<=1+dist;i++){
            lg.insert(nums[i]);
        }
        long long cur=0;
        for(int i=0;i<k;i++){
            auto it=lg.begin();
            sm.insert(*it);
            cur+=*it;
            lg.erase(lg.find(*it));
        }
        long long ans=cur;
        for(int i=dist+2;i<n;i++){
            int num=nums[i];
            int prv=nums[i-dist-1];
            if(lg.count(prv)){
                lg.erase(lg.find(prv));
            }
            else{
                sm.erase(sm.find(prv));
                cur-=prv;
            }
            if(num<=*sm.rbegin()){
                sm.insert(num);
                cur+=num;
            }
            else{
                lg.insert(num);
            }
            while(sm.size()>k){
                auto it=sm.rbegin();
                cur-=*it;
                lg.insert(*it);
                sm.erase(sm.find(*it));
            }
            while(sm.size()<k){
                auto it=lg.begin();
                cur+=*it;
                sm.insert(*it);
                lg.erase(lg.find(*it));
            }
            ans=min(cur,ans);
        }
        return ans+nums[0];
    }
};