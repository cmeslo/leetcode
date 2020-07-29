class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0, cycle = 0;
        
        for (char& c : tasks)
            maxFreq = max(maxFreq, ++freq[c - 'A']);
        
        for (int f : freq)
            if (f == maxFreq) cycle++;
        
        int ans = (maxFreq - 1) * (n + 1) + cycle;
        
        return ans < tasks.size() ? tasks.size() : ans;
    }
};
