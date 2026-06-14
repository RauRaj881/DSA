class Solution {
public:
    int getLength(vector<int>& nums){
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            unordered_map<int,int> st; // freq -> count

            for(int j=i;j<n;j++){

                int old = mp[nums[j]];
                if(old){
                    st[old]--;
                    if(st[old]==0) st.erase(old);
                }

                mp[nums[j]]++;
                st[mp[nums[j]]]++;

                if(mp.size()==1){
                    ans=max(ans,j-i+1);
                }
                else{
                    if(st.size()==2){
                        auto it=st.begin();
                        int mn=it->first;
                        ++it;
                        int mx=it->first;

                        if(mx<mn) swap(mx,mn);

                        if(mx==2*mn)
                            ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
        
    }
};