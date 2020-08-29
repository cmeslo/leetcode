class Solution {
private:
    vector<vector<int>> rects;
    vector<int> rects_cum_sum;
    int pts_sum;
    
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        pts_sum = 0;
        
        for (const auto& rect : rects) {
            int w = rect[2] - rect[0] + 1;
            int h = rect[3] - rect[1] + 1;
            pts_sum += w * h;
            rects_cum_sum.push_back(pts_sum);
        }
    }
    
    vector<int> pick() {
        int pt_idx = rand() % pts_sum;
        int l = 0, r = rects.size() - 1;
        
        while (l < r) {
            int mid = l + (r-l)/2;
            if (rects_cum_sum[mid] <= pt_idx) l = mid + 1;
            else r = mid;
        }
        
        auto& rect = rects[l];
        int w = rect[2] - rect[0] + 1;
        int h = rect[3] - rect[1] + 1;
        int pt_start = rects_cum_sum[l] - w*h;
        int offset = pt_idx - pt_start;
        return {rect[0] + offset % w, rect[1] + offset / w};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
