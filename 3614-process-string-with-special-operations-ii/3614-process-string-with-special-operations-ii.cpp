class Solution {
public:
    char processStr(string s, long long k){
        int n=s.size();
        vector<long long> len(n);
        long long cr=0;
        for(int i=0;i<n;i++){
            if(islower(s[i])){cr++;}
            else if(s[i]=='*'){if(cr>0)cr--;}
            else if(s[i]=='#'){cr*=2;}
            len[i]=cr;
        }
        if(k>=len[n-1]){return '.';}
        for(int i=n-1;i>=0;i--){
            long long prv=(i==0?0:len[i-1]);
            if(islower(s[i])){
                if(k==prv){return s[i];}
            }
            else if(s[i]=='#'){
                k%=prv;
            }
            else if(s[i]=='%'){
                k=prv-k-1;
            }
        }
        return 'kuchh bhi';
    }
};