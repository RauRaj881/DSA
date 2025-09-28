class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long x=10;
        vector<int> v;
        while(n!=0){
            long long p=n%x;
            if(p!=0){v.push_back(p);n-=p;}
            //else{v.push_back(n);n=0;}
            x*=10;
        }
        sort(v.begin(),v.end(),greater<int>());
        return v;
    }
};