class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r_ = radius;
        x_ = x_center;
        y_ = y_center;
    }
    
    vector<double> randPoint() {
        double theta = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double r = sqrt((double) rand() / RAND_MAX) * r_;
        double y = r * sin(theta);
        double x = r * cos(theta);
        return {x_ + x, y_ + y};
    }
    
private:
    double x_, y_;
    double r_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
