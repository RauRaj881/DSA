class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> v{{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
        string ans="";
        while(num!=0){
                for(int i=12;i>=0;i--){
                    if(num>=v[i].second){
                        num-=v[i].second;
                        ans+=v[i].first;
                        break;
                    }
                }
            }
        return ans;
    }
};