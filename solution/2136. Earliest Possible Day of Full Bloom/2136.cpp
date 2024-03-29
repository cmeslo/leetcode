class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> A(n);
        for (int i = 0; i < n; ++i) A[i] = i;
        
        sort(begin(A), end(A), [&](int i, int j) {
            return growTime[i] > growTime[j];
        });
        
        int ans = 0;
        int plantTotal = 0;
        for (int i : A) {
            plantTotal += plantTime[i];
            ans = max(ans, plantTotal + growTime[i]);
        }
        return ans;
    }
};
