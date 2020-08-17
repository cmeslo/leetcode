class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        
        for (int cnt : citations) {
            if (cnt > n) buckets[n]++;
            else buckets[cnt]++;
        }
        
        int count = 0;
        for (int i = n; i >= 1; i--) {
            count += buckets[i];
            if (count >= i) return i;
        }
        
        return count;
    }
};
