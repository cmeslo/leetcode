class Solution {
public:
    int bestClosingTime(string customers) {
        int p = count(customers.begin(), customers.end(), 'Y'), min_p = p, j = 0;
        for (int i = 0; i < customers.size(); ++i) {
            p += customers[i] == 'Y' ? -1 : 1;
            if (p < min_p) {
                min_p = p;
                j = i + 1;
            }
        }
        return j;
    }
};
