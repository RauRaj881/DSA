class Solution {
public:
    int hammingWeight(int n){
        int ans=0;
        for(int i=0;i<=30;i++){
            if((1<<i)&(n)){ans++;}
        }
        return ans;
    }
};