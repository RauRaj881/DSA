class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int> st;
        unordered_map<int,int> mp;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                st.insert(i);
            }
            else{
                if(!mp.count(rains[i])){ans[i]=-1;}
                else{
                    auto it=st.lower_bound(mp[rains[i]]);
                    if(it==st.end()){return {};}
                    else{
                        ans[*it]=rains[i];
                        st.erase(it);
                        //mp.erase(rains[i]);
                        ans[i]=-1;
                    }
                }
            }
            mp[rains[i]]=i;
        }
        return ans;
    }
};