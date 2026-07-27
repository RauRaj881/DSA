class Solution {
public:
static bool cmp(string& a,string& b){
    if(a.size()==b.size()){return a<b;}
    return a.size()<b.size();
}
    int longestStrChain(vector<string>& w){
        sort(w.begin(),w.end(),cmp);
        int n=w.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string a=w[i],b=w[j];
                int cnt=0;
                if(a.size()!=b.size()+1||dp[j]+1<dp[i]){continue;}
                int k1=0,k2=0;
                while(k1<a.size()&&k2<b.size()){
                    if(a[k1]==b[k2]){k1++;k2++;}
                    else{cnt++;k1++;}
                }
                if(cnt==1||k1==a.size()-1){dp[i]=dp[j]+1;}
            }
        }
        int ans=0;
        for(auto it:dp){ans=max(ans,it);}
        return ans;
    }
};