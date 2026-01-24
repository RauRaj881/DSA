class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod=1e9+7;
        int m=r-l+1;
        vector<long long> up(m,0);
        vector<long long> down(m,0);

        for(int x=0;x<m;x++){
            for(int y=0;y<m;y++){
                if(x==y){continue;}
                else if(x>y){
                    down[y]=(down[y]+1)%(mod);
                }
                else{
                    up[y]=(up[y]+1)%(mod);
                }
            }
        }
        vector<long long> prevup=up;
        vector<long long> prevdown=down;
        for(int i=2;i<n;i++){
            vector<long long> predown(m,0);
            vector<long long> preup(m,0);
            for(int j=0;j<m;j++){
                predown[j]=((j>0?predown[j-1]:0)+prevdown[j])%(mod);
                preup[j]=((j>0?preup[j-1]:0)+prevup[j])%(mod);
            }
            for(int x=0;x<m;x++){
                up[x]=((x>0?predown[x-1]:0))%(mod);
                down[x]=(((preup[m-1]-preup[x]))%mod+mod)%(mod);
            }
            prevup=up;prevdown=down;
        }
        long long ans=0;
        for(int val=0;val<m;val++){
            ans=(ans+up[val]+down[val])%(mod);
        }
        return ans;
        
    }
};