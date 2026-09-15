class Solution {
public:
    string getPermutation(int n, int k){
        string ans="";
        unordered_set<int> st;
        vector<int> fact(n+1,1);
        int cr=1;
        for(int i=1;i<=n;i++){
            cr*=i;
            fact[i]=cr;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(st.count(j)){continue;}
                int af=fact[n-i];
                if(af<k){k-=af;}
                else{ans+=j+'0';st.insert(j);break;}
            }
        }
        return ans;
    }
};