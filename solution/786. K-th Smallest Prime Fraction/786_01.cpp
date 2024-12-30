class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        using pii = pair<int, int>;
        auto cmp = [](pii a, pii b) {
            return a.first * b.second < a.second * b.first;
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        const int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pq.push({arr[i], arr[j]});
                if (pq.size() > k)
                    pq.pop();
            }
        }

        return {pq.top().first, pq.top().second};
    }
};
