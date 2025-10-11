class Solution {
public:
    bool scoreBalance(string s) {
        int n=s.size();
        vector<int> presum(n);
        presum[0]=s[0]-'a'+1;
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+(s[i]-'a'+1);
        }
        int tot=presum[n-1];
        if(tot%2!=0){return false;}
        for(int i=0;i<n;i++){
            if(presum[i]==tot/2){return true;}
            else if(presum[i]>tot/2){break;}
        }
        return false;
    }
};