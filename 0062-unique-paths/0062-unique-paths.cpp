class Solution {
public:
    int uniquePaths(int m, int n){
        vector<int> cr(n);
        vector<int> prv(n,0);
        cr[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){continue;}
                int lt=0,up=0;
                if(j>0){lt=cr[j-1];}
                if(i>0){up=prv[j];}
                cr[j]=lt+up;
            }
            prv=cr;
        }
        return prv[n-1];
    }
};