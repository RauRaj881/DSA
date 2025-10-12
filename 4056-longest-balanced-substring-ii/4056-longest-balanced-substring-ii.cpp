class Solution {
public:
void solve(char x,char y ,int &mx,string s){
    unordered_map<int,int> mp;
    mp[0]=-1;
    int presum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==x){presum++;}
        else if(s[i]==y){presum--;}
        else{
            mp.clear();
            presum=0;
            mp[0]=i;
            continue;
        }
        if(mp.count(presum)){mx=max(mx,i-mp[presum]);}
        else{mp[presum]=i;}
    }
}
    int longestBalanced(string s) {
        int n=s.size();
        int mx=1;
        //case 1
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){cnt++;mx=max(mx,cnt);}
            else{cnt=1;}
        }
        // case 2
        solve('a','b',mx,s);
        solve('b','c',mx,s);
        solve('a','c',mx,s);
        // case 3
        map<pair<int,int>,int> mp2;
        mp2[{0,0}]=-1;
        int cnta=0,cntb=0,cntc=0;
        for(int i=0;i<n;i++){
        if(s[i]=='a'){cnta++;}
        else if(s[i]=='b'){cntb++;}
        else{cntc++;}
        int diff1=cnta-cntb;
        int diff2=cnta-cntc;
        if(mp2.count({diff1,diff2})){
            mx=max(mx,i-mp2[{diff1,diff2}]);
        }
        else{
            mp2[{diff1,diff2}]=i;
        }
        }
        return mx;
    }
};
