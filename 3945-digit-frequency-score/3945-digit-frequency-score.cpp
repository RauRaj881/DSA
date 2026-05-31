class Solution {
public:
    int digitFrequencyScore(int n){
        vector<int> fr(10);
        while(n!=0){
            fr[n%10]++;
            n/=10;
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans+=i*fr[i];
        }
        return ans;
        
    }
};