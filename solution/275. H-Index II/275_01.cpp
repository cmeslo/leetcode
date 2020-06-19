class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int cnt = 0;
        for (int i = n-1; i >= 0; i--, cnt++) {
            if (cnt >= citations[i]) return cnt;
        }
        return n;
    }
};
