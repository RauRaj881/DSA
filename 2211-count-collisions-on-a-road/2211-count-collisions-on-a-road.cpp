class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size();
        int cnt=0;
        for(int i=0;i<dir.size()-1;i++){
            if(dir[i]=='R'&&dir[i+1]=='L'){
                dir[i+1]='S';
                dir.erase(dir.begin()+i);
                cnt+=2;
            }
        }
        int n2=dir.size();
        int pos1=0;
        for(int i=0;i<n2;i++){
            if(dir[i]=='S'){pos1=1;}
            else if(dir[i]=='L'&&pos1==1){cnt++;}
        }
        int pos2=0;
        for(int i=n2-1;i>=0;i--){
            if(dir[i]=='S'){pos2=1;}
            else if(dir[i]=='R'&&pos2==1){cnt++;}
        }
        return cnt;
    }
};