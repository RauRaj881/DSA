class Solution {
public:
    string generateString(string str1, string str2){
        int n=str1.size();
        int m=str2.size();
        string ans(n+m-1,'*');
        unordered_set<int> st;
        int lt=-1;
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                if(ans[i]=='*'){
                    for(int j=0;j<m;j++){ans[i+j]=str2[j];}
                }
                else{
                    if(lt!=-1){
                        int df=i-lt;
                        if(ans.substr(i,max(m-df,0))!=str2.substr(0,max(0,m-df))){return "";}
                        else{for(int j=0;j<m;j++){ans[i+j]=str2[j];}}
                    }
                }
                lt=i;
            }
        }
        for(int i=0;i<n+m-1;i++){if(ans[i]=='*'){ans[i]='a';st.insert(i);}}
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                if(ans.substr(i,m)==str2){
                    bool pos=false;
                    for(int j=i+m-1;j>=i;j--){
                        if(st.count(j)){
                            if(ans[j]=='a'){ans[j]='b';}
                            else{ans[j]='a';}
                            pos=true;break;
                        }
                    }
                    if(!pos){return "";}
                }
            }
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){if(ans.substr(i,m)!=str2){return "";}}
            else{if(ans.substr(i,m)==str2){return "";}}
        }
        return ans;
    }
};