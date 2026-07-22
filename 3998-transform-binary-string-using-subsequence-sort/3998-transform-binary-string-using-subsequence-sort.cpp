class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs){
        int n=s.size();
        int m=strs.size();
        vector<bool> ans(m);
        vector<int> v1(n,0);
        vector<int> v0(n,0);
        if(s[n-1]=='0'){v0[n-1]=1;}else{v1[n-1]=1;}
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){v0[i]=v0[i+1]+1;v1[i]=v1[i+1];}
            else{v1[i]=v1[i+1]+1;v0[i]=v0[i+1];}
        }
        for(int j=0;j<m;j++){
            string tp=strs[j];
            int fxd1=0;
            for(auto it:tp){if(it=='1'){fxd1++;}}
            int needed1=v1[0]-fxd1;
            if(needed1<0){ans[j]=false;continue;}
            int cnt1=0,cnt0=0,cnt2=0;
            bool pos=true;
            for(int i=n-1;i>=0;i--){
                if(tp[i]=='0'){cnt0++;}
                else if(tp[i]=='1'){cnt1++;}
                else{
                    if(needed1>0){cnt1++;needed1--;}
                    else{cnt0++;}
                }
                if(v0[i]<cnt0){pos=false;}
            }
            if(cnt1>v1[0]||cnt0>v0[0]||!pos){ans[j]=false;}
            else{ans[j]=true;}
        }
        return ans;
    }
};