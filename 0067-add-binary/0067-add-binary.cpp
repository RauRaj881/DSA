class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry =0;
        int n1=a.size();
        int n2=b.size();
        int i1=n1-1;
        int i2=n2-1;
        while(i1>=0||i2>=0||carry>0){
            if(i1>=0){carry+=a[i1]-'0';i1--;}
            if(i2>=0){carry+=b[i2]-'0';i2--;}
            ans+=(carry%2+'0');
            carry=carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};