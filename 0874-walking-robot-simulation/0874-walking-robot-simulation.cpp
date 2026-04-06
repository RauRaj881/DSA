class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs){
        set<pair<int,int>> st;
        for(int i=0;i<obs.size();i++){
            st.insert({obs[i][0],obs[i][1]});
        }
        char c='n';
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<cmd.size();i++){
            int vl=cmd[i];
            if(vl==-2){
                if(c=='n'){c='w';}
                else if(c=='w'){c='s';}
                else if(c=='s'){c='e';}
                else{c='n';}
            }
            else if(vl==-1){
                if(c=='n'){c='e';}
                else if(c=='w'){c='n';}
                else if(c=='s'){c='w';}
                else{c='s';}
            }
            else{
                bool pos=false;
                while(!pos&&vl--){
                    int fy=y,fx=x;
                    if(c=='n'){fy++;}
                    else if(c=='w'){fx--;}
                    else if(c=='s'){fy--;}
                    else{fx++;}
                    if(st.count({fx,fy})){pos=true;}
                    else{ans=max(ans,(fx*fx+fy*fy));x=fx;y=fy;}
                }
            }
        }
        return ans;
    }
};