class Solution {
public:
    vector<int> validSequence(string w1,string w2){
        int n=w1.size();
        int m=w2.size();
        vector<int> suf(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0&&w1[i]==w2[j]){
                suf[i]=suf[i+1]+1;j--;
            }
            else{
                suf[i]=suf[i+1];
            }
        }
        vector<int> seq;
        j=0;
        bool skp=false;
        for(int i=0;i<n&&j<m;i++){
            if(w1[i]==w2[j]){seq.push_back(i);j++;}
            else if(skp){continue;}
            else{
                if(suf[i+1]>=m-j-1){
                skp=true;
                seq.push_back(i);j++;}
                //else{j++;}
            }
        }
        if(seq.size()==m){return seq;}
        return {};
    }
};