class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++){
            int cnt=0;
            int j=n-1;
            while(j>=0&&grid[i][j]==0){
                cnt++;
                j--;
            }
            if(cnt==n){cnt-=1;}
            if(!mp.count(cnt)){
                mp[cnt]=i;
                mp2[i]=cnt;
            }
            else{
                int cr=cnt-1;
                while(cr>0&&mp.count(cr)){
                    cr--;
                }
                if(cr>0){mp[cr]=i;mp2[i]=cr;}
            }
        }
        for(int i=1;i<=n-1;i++){
            if(!mp.count(i)){return -1;}
        }
        int ans=0;
        for(int cnt=n-1;cnt>=1;cnt--){
            int tar=(n-1)-cnt;
            if(mp2[tar]==cnt){continue;}
            else{
                if(mp[cnt]>tar){
                    int x=mp[cnt]-1;
                    for(int j=x;j>=tar;j--){
                        ans++;
                        int nm=mp2[j];
                        mp[nm]=mp[cnt];
                        mp[cnt]=mp[cnt]-1;
                        mp2[j]=cnt;
                        mp2[j+1]=nm;
                    }
                }
                else{
                    int x=mp[cnt]+1;
                    for(int j=x;j<=tar;j++){
                        ans++;
                        int nm=mp2[j];
                        mp[nm]=mp[cnt];
                        mp[cnt]=mp[cnt]+1;
                        mp2[j]=cnt;
                        mp2[j-1]=nm;
                    }
                }
            }
        }
        return ans;
    }
};