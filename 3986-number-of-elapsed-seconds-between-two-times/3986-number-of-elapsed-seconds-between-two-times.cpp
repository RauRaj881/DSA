class Solution {
public:
    int secondsBetweenTimes(string stt,string edt){
        int ans=0; 
        string h1=stt.substr(0,2);
        int tp1=stoi(h1); 
        string h2=edt.substr(0,2); 
        int tp2=stoi(h2); 
        string h3=stt.substr(3,2); 
        int tp3=stoi(h3); 
        string h4=edt.substr(3,2); 
        int tp4=stoi(h4); 
        string h5=stt.substr(6,2); 
        int tp5=stoi(h5); 
        string h6=edt.substr(6,2); 
        int tp6=stoi(h6); 
        ans=(tp2*3600+tp4*60+tp6);
        ans-=(tp1*3600+tp3*60+tp5);
        return ans;
    }
};