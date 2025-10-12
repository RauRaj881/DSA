class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0); 
            for(int j=i;j<n;j++){
               freq[s[j]-'a']++;
               int g=-1;
               bool pos=true;
               for(int k=0;k<26;k++){
                if(freq[k]==0){continue;}
                else if(g==-1){g=freq[k];}
                else if(freq[k]!=g){pos=false;break;}
               }
               if(pos){ans=max(ans,j-i+1);}
            }    
        }
        return ans;
    }
};