class Solution {
public:
    int minMutation(string sG, string eG, vector<string>& bank) {
        int n=bank.size();
        unordered_set<string> uni;
        for(int i=0;i<n;i++){
            uni.insert(bank[i]);
        }
        if(sG==eG){return 0;}
        if(n==0||!uni.count(eG)){return -1;}
        queue<string> q;
        q.push(sG);
        unordered_set<string> st;
        st.insert(sG);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string temp=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    string s1=temp,s2=temp,s3=temp;
                    if(temp[i]=='A'){
                        s1[i]='C';s2[i]='G',s3[i]='T';
                    }
                    else if(temp[i]=='C'){
                        s1[i]='A';s2[i]='G',s3[i]='T';
                    }
                    else if(temp[i]=='G'){
                        s1[i]='A';s2[i]='C',s3[i]='T';
                    }
                    else if(temp[i]=='T'){
                        s1[i]='A';s2[i]='C',s3[i]='G';
                    }
                    if(eG==s1||eG==s2||eG==s3){return cnt;}
                    if(!st.count(s1)&&uni.count(s1)){q.push(s1);st.insert(s1);}
                    if(!st.count(s2)&&uni.count(s2)){q.push(s2);st.insert(s2);}
                    if(!st.count(s3)&&uni.count(s3)){q.push(s3);st.insert(s3);}
                }
            }
        }
        return -1;
    }
};