class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos,vector<int>& hlt,string dir){
        int n=pos.size();
        vector<vector<int>> v(n,vector<int>(4));
        for(int i=0;i<n;i++){
            int ps=pos[i];
            int ht=hlt[i];
            char dr=dir[i];
            int x=(dr=='L'?0:1);
            v[i]={ps,ht,x,i};
        }
        sort(v.begin(),v.end());
        stack<vector<int>> st;
        st.push({v[0][1],v[0][2],v[0][3]});
        for(int i=1;i<n;i++){
            int cht=v[i][1];
            int cx=v[i][2];
            if(cx==1){st.push({cht,cx,v[i][3]});}
            else{
                bool pos=false;
                while(!st.empty()&&st.top()[1]==1){
                    int sht=st.top()[0];
                    int sx=st.top()[1];
                    int si=st.top()[2];
                    st.pop();
                    if(cht>sht){cht--;}
                    else if(cht<sht){pos=true;sht--;st.push({sht,sx,si});break;}
                    else{pos=true;break;}
                }
                //if(!pos){st.push({cht,cx,v[i][3]});}
            }
        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top()[2],st.top()[0]});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int> ans2;
        for(int i=0;i<ans.size();i++){
            ans2.push_back(ans[i].second);
        }
        return ans2;
    }
};