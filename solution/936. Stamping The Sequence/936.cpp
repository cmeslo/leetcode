class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<int> ans;
        vector<int> seen(n);
        int total = 0;
        
        while (total < n) {
            bool found = false;
            for (int i = 0; i <= n - stamp.size(); ++i) {
                if (seen[i]) continue;
                int len = unStamp(stamp, target, i);
                if (len == 0) continue;
                seen[i] = 1;
                total += len;
                ans.push_back(i);
                found = true;
            }
            if (!found) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    
private:
    int unStamp(const string& stamp, string& target, int s) {
        int len = stamp.size();
        for (int i = 0; i < stamp.size(); ++i) {
            if (target[s + i] == '*')
                --len;
            else if (target[s + i] != stamp[i])
                return 0;
        }
        if (len != 0)
            std::fill(begin(target) + s, begin(target) + s + stamp.size(), '*');
        return len;
    }
};
