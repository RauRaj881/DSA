class Solution {
public:
    string longestPalindrome(string s){
        int n=s.size();
        int mx=1;
        int idx=0;
        for(int i=0;i<n;i++){
            int cr=i;
            int lt=i-1;int rt=i+1;
            int len=1;
            while(lt>=0&&rt<n){
                if(s[lt]==s[rt]){len+=2;lt--;rt++;}
                else{break;}
            }
            lt=i-1;rt=i+1;
            if(len>mx){mx=len;idx=i;}
            if(lt>=0&&s[i]==s[lt]){len=2;lt--;
            while(lt>=0&&rt<n){
                if(s[lt]==s[rt]){len+=2;lt--;rt++;}
                else{break;}
            }
            }
            if(len>mx){mx=len;idx=i;}
        }
            string ans="";
            int i=idx-mx/2;
            while(mx--){
                ans+=s[i];
                i++;
            }
            return ans;
    }
};