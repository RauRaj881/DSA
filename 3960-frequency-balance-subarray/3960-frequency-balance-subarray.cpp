class Solution {
public:
    int getLength(vector<int>& nums){
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            unordered_map<int,int> st;
            for(int j=i;j<n;j++){
                if(mp[nums[j]]>0){
                    st[mp[nums[j]]]--;
                    if(st[mp[nums[j]]]==0){st.erase(mp[nums[j]]);}
                }
                mp[nums[j]]++;
                st[mp[nums[j]]]++;
                if(mp.size()==1){ans=max(ans,j-i+1);}
                else if(st.size()==2){
                    int mx=0,mn=1e5;
                    for(auto it:st){
                        mx=max(mx,it.first);
                        mn=min(mn,it.first);
                    }
                    if(mx==2*mn){ans=max(ans,j-i+1);}
                }
            }
        }
        return ans;
        
    }
};