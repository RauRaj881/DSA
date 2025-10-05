class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[s1[i]]++;
        }
        int distinct=mp.size();
        int haveCount=0;
        int r=0,l=0;
        bool pos=false;
        while(r<n){
            if(pos==true){break;}
            if(mp[s2[r]]>0){haveCount++;}
            mp[s2[r]]--;
            while(l<=r&&haveCount>=m){
                if(r-l+1==m &&haveCount==m){pos=true;break;}
                mp[s2[l]]++;
                if(mp[s2[l]]>0){haveCount--;}
                l++;
            }
            r++;
        }
        return pos; 
    }
};