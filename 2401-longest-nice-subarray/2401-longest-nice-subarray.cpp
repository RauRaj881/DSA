class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<min(n,i+30);j++){
                bool pos=true;
                for(int k=0;k<=30;k++){
                    if((nums[j] & (1<<k))!=0){
                        if(st.count(k)){
                        pos=false;break;}
                        else{st.insert(k);}
                    }
                }
                if(!pos){break;}
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};