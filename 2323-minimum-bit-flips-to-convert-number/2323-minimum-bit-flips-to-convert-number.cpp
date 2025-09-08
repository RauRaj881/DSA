class Solution {
public:
    int minBitFlips(int start, int goal) {
      int x=(start^goal);
      string s1="";
      while(x!=0){
          s1+=x%2+'0';
          x=x/2;
        }
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='1'){cnt++;}
        }
        return cnt;
    }
};