class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int n = sandwiches.size();
        
        int zeros = 0, ones = 0;
        for (int s : students)
            if (s == 0)
                zeros++;
            else
                ones++;
        
        for (int s : sandwiches) {
            if (s == 0) {
                if (zeros-- == 0)
                    return ones;
            } else {
                if (ones-- == 0)
                    return zeros;
            }
        }
        return 0;
    }
};
