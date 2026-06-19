class Solution {
public:
    double angleClock(int hour,int mnt){
        double d1=mnt*6.0;
        double d2=mnt/2.0+((hour)%12)*30.0;
        double df=abs(d1-d2);
        return min(df, 360.0 - df);
    }
};