class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> v(n,0);
        vector<int> block(n,0);
        sort(events.begin(),events.end(),
        [&](const vector<string>&a,const vector<string> &b){
            int time1=stoi(a[1]);
            int time2=stoi(b[1]);
            if(time1!=time2){
                return time1<time2;
            }
            if(a[0]=="OFFLINE"){
                return true;
            }
            return false;
        });
        for(int i=0;i<events.size();i++){
            vector<string> temp=events[i];
            string type=temp[0];
            int time=stoi(temp[1]);
            if(type=="OFFLINE"){
                int user=stoi(temp[2]);
                block[user]=time+60;
            }
            else{
                if (temp[2] == "ALL") {
                    for (int i = 0; i<n; i++) {
                        v[i]++;
                    }
                } 
                else if (temp[2] == "HERE") {
                    for (int i = 0; i < n; i++) {
                        if (block[i] <= time) {
                            v[i]++;
                        }
                    }
                } 
                else {
                    int idx = 0;
                    for (int i = 0; i < temp[2].size(); i++) {
                        if (isdigit(temp[2][i])) {
                            idx = idx * 10 + (temp[2][i] - '0');
                        }
                        if (i + 1 == temp[2].size() ||
                            temp[2][i + 1] == ' ') {
                            v[idx]++;
                            idx = 0;
                        }
                    }
                }
            } 
        }
        return v;
    }
};