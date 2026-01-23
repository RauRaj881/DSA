class Solution {
public:
bool isvalid(int i,int j,int k,vector<vector<int>>& grid){
    int sm1=0;
    for(int a=j;a<j+k;a++){sm1+=grid[i][a];}
    for(int a=i+1;a<i+k;a++){
        int curr=0;
        for(int b=j;b<j+k;b++){
            curr+=grid[a][b];
        }
        if(curr!=sm1){return false;}
    }
    for(int b=j;b<j+k;b++){
        int curr2=0;
        for(int a=i;a<i+k;a++){
            curr2+=grid[a][b];
        }
        if(curr2!=sm1){return false;}
    }
    int a=i,b=j;
    int d1=0;
    while(a<i+k&&b<j+k){
        d1+=grid[a][b];
        a++;b++;
    }
    if(d1!=sm1){return false;}
    a=i,b=j+k-1;
    int d2=0;
    while(a<i+k&&b>=j){
        d2+=grid[a][b];
        a++;b--;
    }
    if(d2!=sm1){return false;}
    return true;
}
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=1;k+i-1<n&&k+j-1<m;k++){
                    if(isvalid(i,j,k,grid)){
                        mx=max(mx,k);
                    }
                }
            }
        }
        return mx;
    }
};