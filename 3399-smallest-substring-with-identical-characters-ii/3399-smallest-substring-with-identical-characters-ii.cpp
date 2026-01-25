class Solution {
public:
bool ispossible(int mid,string &s,int numOps){
    if(mid==1){
        int op1=0,op2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0'){op1++;}
                else{op2++;}
            }
            else{
                if(s[i]=='1'){op1++;}
                else{op2++;}
            }
        }
        return min(op1,op2)<=numOps;
    }
    int cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){cnt++;}
        else{
            numOps-=(cnt/(mid+1));
            cnt=1;
        }
    }
    numOps-=(cnt/(mid+1));
    return numOps>=0;
}
    int minLength(string s, int numOps) {
        int n=s.size();
        int high=n;
        int low=1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(mid,s,numOps)){
                ans=mid;
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return ans;
        
    }
};