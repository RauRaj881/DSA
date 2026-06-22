class Solution {
public:
    int minLights(vector<int>& lights){
        int n=lights.size();
        vector<int> df(n+1,0);
        for(int i=0;i<n;i++){
            int x=lights[i];
            if(x>0){
                int l=max(0,i-x);
                int r=min(n-1,i+x);
                df[l]++;
                df[r+1]--;
            }
        }
        int ans=0;
        int cr=0;
        int len=0;
        for(int i=0;i<n;i++){
            cr+=df[i];
            if(cr==0){len++;}
            else{
                ans+=(len+2)/3;
                len=0;
            }
        }
        ans+=(len+2)/3;
        return ans;
    }
};