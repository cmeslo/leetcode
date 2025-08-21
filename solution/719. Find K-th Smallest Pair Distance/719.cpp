class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = nums[n - 1] - nums[0], mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (count(nums, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    
    int count(vector<int>& A, int x) {
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            int r = upper_bound(A.begin() + i + 1, A.end(), A[i] + x) - A.begin() - 1;
            cnt += r - i;
        }
        return cnt;
    }
};

// x x x x x x x
//       i   j

// A[j] - A[i] <= x
// A[j] <= x + A[i]
