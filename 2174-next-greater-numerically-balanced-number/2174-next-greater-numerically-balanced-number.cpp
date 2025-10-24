class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            int x=i;
            vector<int> v(10,0);
            while(x!=0){
                v[x%10]++;
                x=x/10;
            }
            bool pos=true;
            for(int i=0;i<=9;i++){
                if(v[i]>0&&v[i]!=i){
                    pos=false;break;
                }
            }
            if(pos){return i;}
        }
        return 0;
    }
};