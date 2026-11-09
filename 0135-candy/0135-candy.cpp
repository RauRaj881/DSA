class Solution {
public:
    int candy(vector<int>& ratings){
        int n=ratings.size();
        int up=0,down=0,peak=0,ans=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                up++;
                ans+=1+up;
                down=0;
                peak=up;
            }
            else if(ratings[i]<ratings[i-1]){
                down++;
                ans+=down;
                up=0;
                if(down>peak){ans++;}
            }
            else{
                down=0;up=0;peak=0;ans++;
            }
        }
        return ans;
    }
};