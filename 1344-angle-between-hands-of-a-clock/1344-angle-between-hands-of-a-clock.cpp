class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minangle=minutes*6.0;
        double hourangle=(hour%12)*30.0+minutes*0.5;
        double diff=abs(hourangle-minangle);
        return min(diff,360.0-diff);
    }
};