class Solution {
public:
    int minAddToMakeValid(string s){
        int openNeeded=0;
        int closeNeeded=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                closeNeeded++;
            }
            else{
                if(closeNeeded>0){closeNeeded--;}
                else{openNeeded++;}
            }
        }
        return openNeeded+closeNeeded;
    }
};