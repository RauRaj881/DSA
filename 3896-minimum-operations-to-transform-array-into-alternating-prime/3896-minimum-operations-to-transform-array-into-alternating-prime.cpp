typedef long long ll;
static ll v[1000005];
    static ll p[1000005];
bool pos=false;
    void f(){
        if(pos){return;}
        v[0]=v[1]=1;
        for(ll i=2;i<1e6;i++){
            //if(v[i]==0){
            for(ll j=i*i;j<=1e6;j++){
                if(j%i==0){v[j]=1;}
            //}
            }
        }
        int lt=-1;
        for(ll i=1e6;i>=0;i--){
            if(v[i]==0){lt=i;}
            p[i]=lt;
        }
        pos=true;
    }
class Solution {
public:
    int minOperations(vector<int>& nums){
        int n=nums.size();
        f();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(i%2==1){
                if(v[x]==0){
                    if(x==2){ans+=2;}
                    else{ans+=1;}
                }
            }
            else{
                if(v[x]==1){
                    ans+=(p[x]-x);
                }
            }
        }
        return ans;
    }
};