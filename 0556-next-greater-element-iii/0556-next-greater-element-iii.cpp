class Solution {
public:
    int nextGreaterElement(int n){
        string s=to_string(n);
        int i=s.size()-2;
        while(i>=0&&s[i]>=s[i+1]){i--;}
        if(i<0){return -1;}
        int j=s.size()-1;
        while(i<j){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
                sort(s.begin()+i+1,s.end());
                long long nm=stoll(s);
                if(nm>(long long)INT_MAX){return -1;}
                return (int)nm;
            }
            else{j--;}
        }
        return -1;
    }
};