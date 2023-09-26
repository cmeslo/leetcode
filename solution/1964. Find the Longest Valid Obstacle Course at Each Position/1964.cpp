class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res;
        vector<int> A;
        for (int x : obstacles) {
            if (A.empty() || A.back() <= x) {
                A.push_back(x);
                res.push_back(A.size());
            } else {
                int i = upper_bound(A.begin(), A.end(), x) - A.begin();
                A[i] = x;
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
