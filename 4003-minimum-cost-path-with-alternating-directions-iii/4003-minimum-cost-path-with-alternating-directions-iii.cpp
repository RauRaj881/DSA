#define ll long long
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& p){
        vector<vector<vector<ll>>> dst(m,vector<vector<ll>>(n,vector<ll>(2,1e18)));
        ll dx[4]={-1,0,1,0};
        ll dy[4]={0,1,0,-1};
        set<vector<ll>> st;
        st.insert({1,0,0,1});
        dst[0][0][1]=p[0][0];
        while(!st.empty()){
            vector<ll> cr=*st.begin();
            ll w=cr[0],x=cr[1],y=cr[2],tp=cr[3];
            st.erase(st.begin());
            if(dst[x][y][1-tp]>w+p[x][y]){st.insert({w+p[x][y],x,y,1-tp});dst[x][y][1-tp]=w+p[x][y];}
            if(x==m-1&&y==n-1){return w;}
            //if(dst[x][y][tp]!=w){continue;}
            for(int i=0;i<4;i++){
                ll nx=x+dx[i],ny=y+dy[i];
                if(nx<0||nx>=m||ny<0||ny>=n){continue;}
                ll nw=w+(nx+1)*(ny+1);
                if(tp==1){
                    if((i==1||i==2)&&dst[nx][ny][1-tp]>nw){
                        st.insert({nw,nx,ny,1-tp});
                        dst[nx][ny][1-tp]=nw;
                    }
                    else if((i==0||i==3)&&dst[nx][ny][1-tp]>nw+p[x][y]){
                        st.insert({nw+p[x][y],nx,ny,1-tp});
                        dst[nx][ny][1-tp]=nw+p[x][y];
                    }
                }
                else{
                    if((i==0||i==3)&&dst[nx][ny][1-tp]>nw){
                        st.insert({nw,nx,ny,1-tp});
                        dst[nx][ny][1-tp]=nw;
                    }
                    else if((i==1||i==2)&&dst[nx][ny][1-tp]>nw+p[x][y]){
                        st.insert({nw+p[x][y],nx,ny,1-tp});
                        dst[nx][ny][1-tp]=nw+p[x][y];
                    }
                }
            }
        }
        return -1;
    }
};