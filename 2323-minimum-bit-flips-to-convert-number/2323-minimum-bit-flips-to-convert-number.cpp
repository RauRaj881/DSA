class Solution {
public:
    int minBitFlips(int start, int goal) {
      int x=(start^goal);
      string s1="";
      int cnt=0;
      while(x!=0){
          if(x%2==1){cnt++;}
          x=x/2;
        }
        return cnt;
    }
};