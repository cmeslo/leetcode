class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        static vector<int> seqs;
        
        if (seqs.empty()) {
            for (int i = 1; i < 10; ++i) {
                int cur = 0;
                dfs(i, cur, seqs);
            }
            sort(begin(seqs), end(seqs));
        }
        
        vector<int> ans;
        for (int seq : seqs) {
            if (seq > high) break;
            if (low <= seq) ans.push_back(seq);
        }
        
        return ans;
    }
    
private:
    void dfs(int start, int& cur, vector<int>& seqs) {
        if (start > 9) return;
        
        cur = cur * 10 + start;
        if (cur > 10) seqs.push_back(cur);
        dfs(start + 1, cur, seqs);
    }
};
