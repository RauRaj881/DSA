class Solution {
public:
    double angleClock(int hour,int min){
        double d1=min*6.0;
        double d2=min/2.0+((hour)%12)*30.0;
        double df=abs(d1-d2);
        return std::min(df, 360.0 - df);
    }
};