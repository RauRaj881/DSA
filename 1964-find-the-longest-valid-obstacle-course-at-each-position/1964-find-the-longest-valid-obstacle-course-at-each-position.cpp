class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        int n=o.size();
        vector<int> ans(n);
        vector<int> tails;
        for(int i=0;i<n;i++){
            int num=o[i];
            auto it=upper_bound(tails.begin(),tails.end(),num);
            if(it==tails.end()){
                tails.push_back(num);
                ans[i]=tails.size();
            }
            else{
                int idx=it-tails.begin();
                ans[i]=idx+1;
                tails[idx]=num;
            }
        }
        return ans;
    }
};