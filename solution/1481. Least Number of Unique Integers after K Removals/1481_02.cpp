class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (int x : arr)
            ++m[x];
        
        for (auto it : m)
            pq.push(it.second);
        
        while (k > 0) {
            if (k < pq.top())
                break;
            k -= pq.top(); pq.pop();
        }
        return pq.size();
    }
};
