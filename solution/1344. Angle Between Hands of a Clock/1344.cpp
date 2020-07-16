class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour + (double)minutes/60) * 30;
        double m = minutes * 6;
        double angle = abs(m - h);
        return min(angle, 360 - angle);
    }
};
