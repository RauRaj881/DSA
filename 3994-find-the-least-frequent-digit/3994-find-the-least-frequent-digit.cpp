class Solution {
public:
void recur(int n,map<int,int>&mp){
    if(n==0){return;}
    int rem=n%10;
    mp[rem]++;
    recur(n/10,mp);
}
    int getLeastFrequentDigit(int n) {
        map<int,int> mp;
        recur(n,mp);
        int x=INT_MAX;
        int p;
        for(auto it=mp.begin();it!=mp.end();it++){
           if(it->second<x){
            p=it->first;
            x=it->second;
           }
           else if(it->second==x){
            if(it->first<p){
                p=it->first;
            }
           }
        }
        return p;
    }
};