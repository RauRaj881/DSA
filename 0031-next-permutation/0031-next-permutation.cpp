class Solution {
public:
    void nextPermutation(vector<int>& s) {
        int i=s.size()-2;
        while(i>=0&&s[i]>=s[i+1]){i--;}
        if(i<0){reverse(s.begin(),s.end());return;}
        int j=s.size()-1;
        while(i<j){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
                sort(s.begin()+i+1,s.end());
                // nm=stoi(s);
                //if(nm>(long long)INT_MAX){return -1;}
                return;
            }
            else{j--;}
        }
        return;
    }
};