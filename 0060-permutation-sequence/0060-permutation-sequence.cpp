class Solution {
public:
int fact(int i){
    int ans=1;
    for(int k=1;k<=i;k++){
        ans*=k;
    }
    return ans;
}
    string getPermutation(int n, int k){
        string ans="";
        unordered_set<int> st;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(st.count(j)){continue;}
                int af=fact(n-i);
                if(af<k){k-=af;}
                else{ans+=j+'0';st.insert(j);break;}
            }
        }
        return ans;
    }
};