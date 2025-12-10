class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        multiset<int> ms;
        long long ans=1;
        long long mod=1e9+7;
        ms.insert(complexity[0]);
        for(int i=1;i<n;i++){
            int num=complexity[i];
            auto it = ms.lower_bound(num);
            if(it==ms.begin()){return 0;}
        }
        long long k=1;
        for(int i=1;i<n;i++){
            long long x=ans*k;
            ans=(x)%(mod);
            k++;
        }
        return (int)ans;
    }
};