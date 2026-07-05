class Solution {
public:
    int divisibleGame(vector<int>& nums){
        int n=nums.size();
        unordered_set<int> st;
        int mx=1;
        for(int i=0;i<n;i++){
            int nm=nums[i];
            for(int j=2;j*j<=nums[i];j++){
                if(nm%j==0){st.insert(j);
                                while(nm%j==0){
                                    nm/=j;
                                }
                                }
            }
            if(nm>1){st.insert(nm);}
        }
        st.insert(2);
        long long mod=1e9+7;
        long long bstmx=-2e18;
        long long ansit;
        for(auto it:st){
            long long cr=0;
            long long mx=-2e18;
            for(int i=0;i<n;i++){
                if(nums[i]%it==0){cr+=nums[i];}
                else{cr-=nums[i];}
                mx=max(mx,cr);
                if(cr<0){cr=0;}
            }
            if(mx>bstmx){bstmx=mx; ansit=it;}
            else if(mx==bstmx && it<ansit){ansit=it;}
        }
        long long ans=bstmx*ansit;
        return (ans%mod+mod)%mod;
    }
};