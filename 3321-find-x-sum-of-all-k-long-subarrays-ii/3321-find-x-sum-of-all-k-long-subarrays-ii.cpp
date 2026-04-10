typedef long long ll;
class Solution {
public:
ll sm=0;
unordered_map<ll,ll> fr;
void f(set<pair<ll,ll>> &st1,set<pair<ll,ll>> &st2,ll vl,ll x,ll g){
    int fq=0;
            if(st1.count({fr[vl],vl})){
                fq=fr[vl];
                st1.erase({fr[vl],vl});
                sm-=(vl)*fq;
            }
            else if(st2.count({fr[vl],vl})){
                fq=fr[vl];
                st2.erase({fr[vl],vl});
            }
            fr[vl]=fq+g;
            if(fr[vl]>0){st2.insert({fr[vl],vl});}
            while(st1.size()<x&&!st2.empty()){
                auto it=prev(st2.end());
                st1.insert(*it);
                sm+=(ll)(it->first)*(it->second);
                st2.erase(it);
            }
            if(!st1.empty()&&!st2.empty()&&(*st2.rbegin()>*st1.begin())){
                auto it=st1.begin();
                auto it2=prev(st2.end());
                sm+=(it2->first)*(it2->second);
                sm-=(it->first)*(it->second);
                st1.insert({it2->first,it2->second});st2.insert({it->first,it->second});
                st1.erase(it);st2.erase(it2);
            }
}
    vector<long long> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();
        set<pair<ll,ll>> st1;
        set<pair<ll,ll>> st2;
        vector<ll> ans;
        for(int i=0;i<=k-2;i++){
            f(st1,st2,nums[i],x,1);
        }
        for(int i=k-1;i<n;i++){
            if(i>=k){f(st1,st2,nums[i-k],x,-1);}
            f(st1,st2,nums[i],x,1);
            ans.push_back(sm);
        }
        return ans;
    }
};