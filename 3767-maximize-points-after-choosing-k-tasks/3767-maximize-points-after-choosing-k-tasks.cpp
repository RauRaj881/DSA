class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        long long ans=0;
        for(auto it:t1){
            ans+=it;
        }
        vector<int> delta(n);
        for(int i=0;i<n;i++){
            delta[i]=t2[i]-t1[i];
        }
        sort(delta.rbegin(),delta.rend());
        for(int i=0;i<n-k;i++){
            if(delta[i]>0){ans+=delta[i];}
        }
        return ans;
    }
};