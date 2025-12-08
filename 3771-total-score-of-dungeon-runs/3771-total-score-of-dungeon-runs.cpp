class Solution {
public:
    long long totalScore(int hp, vector<int>& dam, vector<int>& req) {
        int n=dam.size();
        vector<long long> predam(n);
        predam[0]=dam[0];
        for(int i=1;i<n;i++){
            predam[i]=predam[i-1]+dam[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long need=predam[i]+req[i]-hp;
            if(need<=0){ans+=i+1;}
            else{
            auto it=lower_bound(predam.begin(),predam.begin()+i,need);
            int idx=it-predam.begin();
            ans+=i-idx;
            }
        }
        return ans;
    }
};