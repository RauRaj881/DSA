class Solution {
public:
    string countAndSay(int n) {
        if(n==1){return "1";}
        string say=countAndSay(n-1);
        string ans="";
        int i=0;
        while(i<say.length()){
            char c=say[i];
            int count=0;
            while(say[i]==c){
                count++;
                i++;
            }
            //i--;
            string s=to_string(count);
            ans+=s;
            ans.push_back(c);
        }
        return ans;
    }
};
