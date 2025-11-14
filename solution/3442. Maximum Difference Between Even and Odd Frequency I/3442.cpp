class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> frequencyMap;
        for (char ch : s) {
            frequencyMap[ch]++;
        }

        int maxOdd = -1;
        int minEven = INT_MAX;

        for (const auto& [_, freq] : frequencyMap) {
            if (freq % 2 == 0) {
                minEven = min(minEven, freq);
            } else {
                maxOdd = max(maxOdd, freq);
            }
        }

        if (maxOdd == -1 || minEven == INT_MAX) {
            return 0;
        }

        return maxOdd - minEven;
    }
};
