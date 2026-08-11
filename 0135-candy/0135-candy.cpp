class Solution {
public:
    int candy(vector<int>& r){
        int n=r.size();
        int up=0,down=0,peak=0,ans=1;
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                up++;
                ans+=1+up;
                peak=up;
                down=0;
            }
            else if(r[i]<r[i-1]){
                down++;
                up=0;
                ans+=down;
                if(down>peak){ans++;}
            }
            else{
                up=0;down=0;peak=0;ans++;
            }
        }
        return ans;
    }
};