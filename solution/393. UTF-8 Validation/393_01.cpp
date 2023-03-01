class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            int len = countLeadingOnes(data[i]);
            if (!checkHeaderValid(data[i], len)) return false;
            if (i + len - 1 >= n) return false;
            int j = i + 1;
            for (; j < i + len; ++j) {
                if (!checkStartWithOneZero(data[j]))
                    return false;
            }
            i = j - 1;
        }
        return true;
    }
    
    int countLeadingOnes(int x) {
        int cnt = 0;
        for (int i = 7; i >= 0 && ((x >> i) & 1); --i)
            ++cnt;
        return cnt;
    }
    
    bool checkHeaderValid(int x, int leadingOnes) {
        return leadingOnes == 0 || (2 <= leadingOnes && leadingOnes <= 4);
    }
    
    bool checkStartWithOneZero(int x) {
        return ((x >> 7) & 1) == 1
            && ((x >> 6) & 1) == 0;
    }
};
