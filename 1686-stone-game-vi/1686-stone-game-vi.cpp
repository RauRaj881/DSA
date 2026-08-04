class Solution {
public:
    int stoneGameVI(vector<int>& a,vector<int>& b){
        vector<pair<int,int>> v;
        for(int i=0;i<a.size();i++){
            v.push_back({a[i]+b[i],i});
        }
        sort(v.rbegin(),v.rend());
        int tp1=0,tp2=0;
        for(int i=0;i<a.size();i++){
            if(i%2==0){
                tp1+=a[v[i].second];
            }
            else{
                tp2+=b[v[i].second];
            }
        }
        if(tp1>tp2){return 1;}
        else if(tp1<tp2){return -1;}
        return 0;
    }
};