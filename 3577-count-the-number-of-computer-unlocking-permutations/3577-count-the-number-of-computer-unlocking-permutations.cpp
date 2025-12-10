class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        long long ans=1;
        long long mod=1e9+7;
        int mn=*min_element(complexity.begin()+1,complexity.end());
        if(mn<=complexity[0]){return 0;}
        for(long long i=1;i<n;i++){
            long long x=ans*i;
            ans=(x)%(mod);
        }
        return (int)ans;
    }
};