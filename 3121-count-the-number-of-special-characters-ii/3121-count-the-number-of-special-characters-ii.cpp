class Solution {
public:
    int numberOfSpecialChars(string word){
        int ans=0;
        for(int nm=97;nm<=122;nm++){
            int idxs=-1;
            int idxl=-1;
            for(int i=0;i<word.size();i++){
                if(int(word[i])==nm-32){
                    if(idxl==-1){idxl=i;}
                }
                if(int(word[i]==nm)){
                    idxs=i;
                }
            }
            if((idxs!=-1&&idxl!=-1)&&idxl>idxs){ans++;}
        }
        return ans;
        
    }
};