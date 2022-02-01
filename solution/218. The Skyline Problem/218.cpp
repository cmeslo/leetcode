class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>> events; // (x, h)
        for (const auto& b : buildings) {
            events.emplace_back(b[0], b[2]);
            events.emplace_back(b[1], -b[2]);
        }
        
        sort(begin(events), end(events), [](const auto& e1, const auto& e2) {
            if (e1.first == e2.first) { // x 相等時
                // e1, e2 都是 entering point, 從高度 大 到 小 排
                // e1, e2 都是 leaving point, 從高度 小 到 大 排
                // e1, e2 分別是 entering point 和 leaving point, 從 entering event 到 leaving event 排
                return e1.second > e2.second;
            }
            return e1.first < e2.first;
        });
        
        ms_.clear();
        
        vector<vector<int>> ans;
        for (auto& e : events) {
            int x = e.first, h = abs(e.second);
            bool entering = e.second > 0;
            
            if (entering) {
                if (h > this->maxHeight()) // 最高點
                    ans.push_back({x, h});
                ms_.insert(h);
            } else {
                ms_.erase(ms_.equal_range(h).first);
                if (h > this->maxHeight()) // 第二高點
                    ans.push_back({x, this->maxHeight()});
            }
        }
        
        return ans;
    }
    
private:
    multiset<int> ms_;
    
    int maxHeight() {
        if (ms_.empty()) return 0;
        return *ms_.rbegin();
    }
};
