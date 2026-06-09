class Solution {
public:
    bool rotateString(string s, string goal) {
        string p=goal;
        if(s.length()!=goal.length()){return 0;}
        for(int i=0;i<s.length();i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal){return 1;}
            //else {s=p;}
        }
        return 0;
    }
};