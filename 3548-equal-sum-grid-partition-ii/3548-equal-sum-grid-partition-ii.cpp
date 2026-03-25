class Solution {
public:
bool f(long long sm,long long x,unordered_map<long long,long long> &mp1,unordered_map<long long,long long> &mp){
    long long diff=abs(2*sm-x);
    if(2*sm>x){
        if(mp1[diff]>0){return true;}
    }
    else{
        if(mp[diff]>mp1[diff]){return true;}
    }
    return false;
}
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        long long tot=0;
        unordered_map<long long,long long> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot+=grid[i][j];
                mp[grid[i][j]]++;
            }
        }
        if(n==1){
            unordered_map<int,int> mtp;
            long long tp=0;
            for(int j=0;j<m;j++){
                tp+=grid[0][j];
                mtp[grid[0][j]]++;
                int diff=abs(2*tp-tot);
                if(2*tp==tot){return true;}
                else if(2*tp>tot){if(mtp[diff]>0&&(grid[0][0]==diff||(grid[0][j]==diff))){return true;}}
                else{if(mp[diff]>mtp[diff]&&(grid[0][m-1]==diff||(j<m-1&&grid[0][j+1]==diff))){return true;}}
            }
            return false;
        }
        if(m==1){
            unordered_map<int,int> mtp;
            long long tp=0;
            for(int i=0;i<n;i++){
                tp+=grid[i][0];
                mtp[grid[i][0]]++;
                int diff=abs(2*tp-tot);
                if(2*tp==tot){return true;}
                else if(2*tp>tot){if(mtp[diff]>0&&(grid[0][0]==diff||(grid[i][0]==diff))){return true;}}
                else{if(mp[diff]>mtp[diff]&&(grid[n-1][0]==diff||(i<n-1&&grid[i+1][0]==diff))){return true;}}
            }
            return false;
        }
        unordered_map<long long,long long> mp1;
        long long sm1=0,sm2=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sm1+=grid[i][j];
                mp1[grid[i][j]]++;
            }
            if(2*sm1==tot){return true;}
            else{
                long long diff=abs(2*sm1-tot);
                if(i==0&&m>2&&2*sm1>tot){if(grid[0][0]==diff||grid[0][m-1]==diff){return true;}}
                else if(i==n-2&&m>2&&2*sm1<tot){
                    if(grid[n-1][0]==diff||grid[n-1][m-1]==diff){return true;}
                }          
                else{
                if(f(sm1,tot,mp1,mp)){return true;}}
            }
        }
        unordered_map<long long,long long> mp2;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                sm2+=grid[i][j];
                mp2[grid[i][j]]++;
            }
            if(2*sm2==tot){return true;}
            else{
                long long diff=abs(2*sm2-tot);
                if(j==0&&n>2&&2*sm2>tot){if(grid[0][0]==diff||grid[n-1][0]==diff){return true;}}
                else if(j==m-2&&n>2&&2*sm2<tot){
                    if(grid[0][m-1]==diff||grid[n-1][m-1]==diff){return true;}
                }
                else{if(f(sm2,tot,mp2,mp)){return true;}}
                }
            }
        return false;
    }
};