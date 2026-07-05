class Solution {
public:
    bool canMakeSubsequence(string s, string t){
        int n1=s.size();
        int n2=t.size();
        if(n1>n2){return false;}
        vector<int> prm(n1,-1);
        vector<int> sfm(n1,n2);
        int i=0,j=0;
        while(i<n1&&j<n2){
            if(s[i]==t[j]){prm[i]=j;i++;j++;}
            else{j++;}
        }
        if(i==n1){return true;}
        i=n1-1,j=n2-1;
        while(i>=0&&j>=0){
            if(s[i]==t[j]){sfm[i]=j;i--;j--;}
            else{j--;}
        }
        if(i==-1){return true;}
        for(int i=0;i<n1;i++){
            int idx1,idx2;
            if(i==0){idx1=-1;}
            else{if(prm[i-1]!=-1){idx1=prm[i-1];}else{continue;}}
            if(i==n1-1){idx2=n2;}
            else{if(sfm[i+1]!=n2){idx2=sfm[i+1];}else{continue;}}
            if(idx2-idx1>=2){return true;}
        }
        return false;
        
    }
};