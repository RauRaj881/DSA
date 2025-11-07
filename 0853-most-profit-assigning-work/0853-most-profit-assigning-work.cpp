class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={difficulty[i],profit[i]};
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int j=0,best=0;
        int ans=0;
        for(int i=0;i<m;i++){
            while(j<n&&worker[i]>=v[j].first){
                best=max(best,v[j].second);
                j++;
            }
            ans+=best;
        }
        return ans;
    }
};
