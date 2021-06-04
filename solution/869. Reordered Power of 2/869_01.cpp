class Solution {
public:
    bool reorderedPowerOf2(int N) {
        static unordered_set<string> powerOfTwo;
        if (powerOfTwo.empty()) {
            for (int i = 0; i < 32; ++i) {
                string str = to_string(1 << i);
                sort(begin(str), end(str));
                powerOfTwo.insert(str);
            }
        }
        
        string str = to_string(N);
        sort(begin(str), end(str));
        return powerOfTwo.count(str);
    }
};
