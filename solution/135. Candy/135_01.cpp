class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        int cnt = 0;

        vector<vector<int>> sortedRatings(n);

        for (int i = 0; i < n; ++i) {
            sortedRatings[i].push_back(ratings[i]);
            sortedRatings[i].push_back(i);
        }

        sort(sortedRatings.begin(), sortedRatings.end(), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        for (int i = 1; i < n; ++i) {
            int index = sortedRatings[i][1];
            if (index - 1 >= 0) {
                if (ratings[index] > ratings[index - 1]) {
                    candies[index] = max(candies[index], candies[index - 1] + 1);
                }
            }
            if (index + 1 < n) {
                if (ratings[index] > ratings[index + 1]) {
                    candies[index] = max(candies[index], candies[index + 1] + 1);
                }
            }
        }

        for (int c : candies) cnt += c;
        return cnt;
    }
};
