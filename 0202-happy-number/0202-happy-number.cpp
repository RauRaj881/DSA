class Solution {
public:
int f(int n){
    int nw=0;
    while(n!=0){
        int dg=n%10;
        nw+=(dg*dg);
        n/=10;
    }
    return nw;
}
    bool isHappy(int n){
        unordered_set<int> st;
        while(n!=1){
            if(st.count(n)){return false;}
            else{st.insert(n);n=f(n);}
        }
        return true;
    }
};