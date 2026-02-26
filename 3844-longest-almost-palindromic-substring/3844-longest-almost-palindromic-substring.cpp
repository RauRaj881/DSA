class Solution {
public:
int chl(int i,int j,string &s){
    int n=s.size();
    int cnt=0;
    int tot=0;
    while(i>=0&&j<n){
        if(i==j){tot++;i--;j++;}
        else{
            if(s[i]==s[j]){tot+=2;i--;j++;}
            else{
                if(cnt==1){break;}
                else{cnt++;tot++;i--;}
            }
        }
    }
    if((i<0&&cnt==0&&j<n)||(j==n&&cnt==0&&i>=0)){tot++;}
    return tot;
}
int chr(int i,int j,string &s){
    int n=s.size();
    int cnt=0;
    int tot=0;
    while(i>=0&&j<n){
        if(i==j){tot++;i--;j++;}
        else{
            if(s[i]==s[j]){tot+=2;i--;j++;}
            else{
                if(cnt==1){break;}
                else{cnt++;tot++;j++;}
            }
        }
    }
    if((i<0&&cnt==0&&j<n)||(j==n&&cnt==0&&i>=0)){tot++;}
    return tot;
}
    int almostPalindromic(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=chl(i,i,s);
            int y=chr(i,i,s);
            ans=max(ans,max(x,y));
            if(i<n-1){
                int a=chl(i,i+1,s);
                int b=chr(i,i+1,s);
                ans=max(ans,max(a,b));
            }
        }
        return ans;
    }
};