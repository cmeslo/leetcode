class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int left = it - arr.begin() - 1;
        int right = it - arr.begin();
        
        deque<int> q;
        while (q.size() < k && left >= 0 && right < n) {
            if (x - arr[left] <= arr[right] - x)
                q.push_front(arr[left--]);
            else
                q.push_back(arr[right++]);
        }
        while (q.size() < k && left >= 0)
            q.push_front(arr[left--]);
        while (q.size() < k && right < n)
            q.push_back(arr[right++]);
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};
