class Solution {
public:
    int longestBalanced(string s){
        int n=s.size();
        int cnt1=0,cnt0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){cnt0++;}
            else{cnt1++;}
        }
        vector<int> pre1(n,0);
        vector<int> pre0(n,0);
        if(s[0]=='0'){pre0[0]=1;pre1[0]=0;}
        else{pre0[0]=0;pre1[0]=1;}
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                pre0[i]=pre0[i-1]+1;
                pre1[i]=pre1[i-1];
            }
            else{
                pre0[i]=pre0[i-1];
                pre1[i]=pre1[i-1]+1;
            }
        }
        unordered_map<int,vector<int>> mp;
        mp[0].push_back(-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int df=pre1[i]-pre0[i];
            if(mp.count(df)){
                ans=max(ans,i-mp[df][0]);
            }
            if(mp.count(df-2)){
                vector<int> arr=mp[df-2];
                for(int j=0;j<arr.size();j++){
                if(mp[df-2][j]>0){
                    if(pre0[mp[df-2][j]-1]>0){ans=max(ans,i-mp[df-2][j]);}
                }
                if(i<n-1){
                    if(pre0[n-1]>pre0[i]){
                        ans=max(ans,i-mp[df-2][j]);
                    }
                }
                }
            }
            if(mp.count(df+2)){
                vector<int> arr=mp[df+2];
                for(int j=0;j<arr.size();j++){
                if(mp[df+2][j]>0){
                    if(pre1[mp[df+2][j]-1]>0){ans=max(ans,i-mp[df+2][j]);}
                }
                if(i<n-1){
                    if(pre1[n-1]>pre1[i]){
                        ans=max(ans,i-mp[df+2][j]);
                    }
                }
                }
            }
            mp[df].push_back(i);
        }
        return ans;
    }
};