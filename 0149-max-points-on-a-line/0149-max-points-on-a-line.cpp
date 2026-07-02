class Solution {
public:
    int maxPoints(vector<vector<int>>& p){
        int n=p.size();
        int mx=min(2,n);
        for(int i=0;i<n;i++){
            map<pair<int,int>,int> mp;
            for(int j=i+1;j<n;j++){
                int dx=p[i][0]-p[j][0];
                int dy=p[i][1]-p[j][1];
                if(dx==0){dy=1;}
                else if(dy==0){dx=1;}
                else{
                    int g=__gcd(dx,dy);
                    dx/=g;
                    dy/=g;
                    if(dx<0){dx*=-1;dy*=-1;}
                }
                mp[{dx,dy}]++;
                mx=max(mx,mp[{dx,dy}]+1);
            }
        }
        return mx;
    }
};