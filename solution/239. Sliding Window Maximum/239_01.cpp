class MonotonicQueue {
private:
    deque<int> _data;

public:
    void push(int e) {
        while (!_data.empty() && _data.back() < e) _data.pop_back();
        _data.push_back(e);
    }
    
    void pop() {
        _data.pop_front();
    }
    
    int max() {
        return _data.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                ans.push_back(q.max());
                if (nums[i - k + 1] == q.max()) q.pop();
            }
        }
        
        return ans;
    }
};
