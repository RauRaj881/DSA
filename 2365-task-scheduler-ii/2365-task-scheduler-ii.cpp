class Solution {
public:
    long long taskSchedulerII(vector<int>& t,int n){
        unordered_map<long long,long long> lt;
        long long tm=0;
        for(int i=0;i<t.size();i++){
            if(!lt.count(t[i])||lt[t[i]]+n+1<=tm){
                lt[t[i]]=tm;
                tm=lt[t[i]]+1;
            }
            else{
                lt[t[i]]=lt[t[i]]+n+1;
                tm=lt[t[i]]+1;
            }
        }
        return tm;
    }
};