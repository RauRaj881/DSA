class Solution {
public:
    int numSub(string s) {
        int ans=0,cnt=0;
        int mod=1e9+7;
        for(auto it:s){
            if(it=='0'){
                cnt=0;
            }
            else{
                cnt++;
            }
            ans=(ans+cnt)%(mod);
        }
        return ans;
    }
};