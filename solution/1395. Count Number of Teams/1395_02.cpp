class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            int leftSmaller = 0, leftGreater = 0, rightSmaller = 0, rightGreater = 0;
            for (int j = 0; j < n; ++j) {
                if (rating[i] < rating[j]) {
                    if (i < j)
                        rightGreater++;
                    else
                        leftGreater++;
                }
                if (rating[j] < rating[i]) {
                    if (j < i)
                        leftSmaller++;
                    else
                        rightSmaller++;
                }
            }
            res += leftSmaller * rightGreater + leftGreater * rightSmaller;
        }
        return res;
    }
};

// x x x x x x x x
//     j   i   j
