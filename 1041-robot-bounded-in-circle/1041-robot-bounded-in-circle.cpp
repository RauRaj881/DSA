class Solution {
public:
    bool isRobotBounded(string instructions){
        int n=instructions.size();
        int cr=1;
        int r=0,c=0;
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='G'){
                if(cr==1){
                    c++;
                }
                else if(cr==2){
                    r++;
                }
                else if(cr==3){
                    c--;
                }
                else{
                    r--;
                }
            }
            else if(instructions[i]=='L'){
                if(cr==1){
                    cr=4;
                }
                else if(cr==2){
                    cr=1;
                }
                else if(cr==3){
                    cr=2;
                }
                else{
                    cr=3;
                }
            }
            else{
                if(cr==1){
                    cr=2;
                }
                else if(cr==2){
                    cr=3;
                }
                else if(cr==3){
                    cr=4;
                }
                else{
                    cr=1;
                }
            }
        }
        return (cr!=1||(r==0&&c==0));
    }
};