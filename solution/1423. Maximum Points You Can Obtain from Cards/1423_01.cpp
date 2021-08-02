class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (n == k) return total;
        int size = n - k;
        
        int ans = 0, sum = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            sum += cardPoints[j];
            if (j - i + 1 == size) {
                ans = max(ans, total - sum);
                sum -= cardPoints[i++];
            }
        }
        return ans;
    }
};
