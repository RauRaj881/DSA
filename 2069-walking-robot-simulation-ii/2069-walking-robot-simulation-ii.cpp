class Robot {
public:
int m,n;
int x=0,y=0;
char c='e';
    Robot(int wd, int ht){
        m=ht;
        n=wd;
    }
    
    void step(int num){
        int cycle = 2 * (m + n - 2);
        num %= cycle;
        if(num==0){num=cycle;}
        while(num--){
            int fx=x,fy=y;
            if(c=='e'){
                if(fx+1==n){c='n';fy++;}
                else{fx++;}
            }
            else if(c=='n'){
                if(fy+1==m){c='w';fx--;}
                else{fy++;}
            }
            else if(c=='w'){
                if(fx-1==-1){c='s';fy--;}
                else{fx--;}
            }
            else{
                if(fy-1==-1){c='e';fx++;}
                else{fy--;}
            }
            x=fx;y=fy;
        }
    }
    
    vector<int> getPos(){
        return {x,y};
    }
    
    string getDir(){
        if(c=='e'){return "East";}
        else if(c=='w'){return "West";}
        else if(c=='n'){return "North";}
        else{return "South";}
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */