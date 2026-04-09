class Solution {
public:
    vector<string> fullJustify(vector<string>& words,int mW){
        int n=words.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int j=i;
            int cnt=0;
            int x=0;
            while(j<n){
                if(j==i){cnt+=words[j].size();x+=words[j].size();j++;}
                else{
                    if(cnt+1+words[j].size()>mW){j--;break;}
                    else if(cnt+1+words[j].size()==mW){x+=words[j].size();break;}
                    else{cnt+=(1+words[j].size());x+=words[j].size();j++;}
                }
            }
            if(j==n){j--;}
            string cr="";
            int tw=j-i+1;
            int sp=tw-1;
            int ns=0;
            int y=mW-x;
            int ad=0;
            if(sp!=0){ns=y/sp;ad=y%sp;}
            if(j==n-1){ad=n;ns=0;}
            for(int idx=i;idx<=j;idx++){
                if(idx==i){cr+=words[idx];}
                else{
                    if(ad>0){cr+=string(1+ns,' ')+words[idx];ad--;}
                    else{cr+=string(ns,' ')+words[idx];}
                }
            }
            if(cr.size()<mW){int df=mW-cr.size();cr+=string(df,' ');}
            ans.push_back(cr);
            i=j+1;
        }
        return ans;
    }
};