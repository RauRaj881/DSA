class Solution {
public:
    vector<string> readBinaryWatch(int tO){
        vector<string> ans;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==tO){
                    string s1,s2;
                    s1=to_string(i);
                    if(j<10){s2="0"+to_string(j);}
                    else{s2=to_string(j);}
                    ans.push_back(s1+":"+s2);
                }
            }
        }
        return ans;
    }
};