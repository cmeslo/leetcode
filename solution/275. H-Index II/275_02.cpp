class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int left = 0, right = n;
        
        while (left < right) {
            int mid = left + (right - left)/2;
            int len = n - mid;
            if (citations[mid] >= len)
                right = mid;
            else
                left = mid + 1;
        }
        
        return n-left;
    }
};
