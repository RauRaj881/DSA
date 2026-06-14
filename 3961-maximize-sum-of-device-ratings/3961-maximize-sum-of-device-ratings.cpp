class Solution {
public:
    long long maxRatings(vector<vector<int>>& units){
        int m=units.size();
        int n=units[0].size();
        long long sm=0;
        if(n==1){
           for(int i=0;i<m;i++){
            sm+=units[i][0];
           }
           return sm; 
        }
        vector<int> f;
        vector<int> s;
        sm=0;
        for(int i=0;i<m;i++){
            vector<int> tp=units[i];
            sort(tp.begin(),tp.end());
            f.push_back(tp[0]);
            s.push_back(tp[1]);
        }
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        for(int i=1;i<s.size();i++){sm+=s[i];}
        sm+=f[0];
        long long sm2=0;
        for(int i=0;i<f.size();i++){sm2+=f[i];}
        return max(sm,sm2);
    }
};