class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128);
        for (char& c : s)
            freq[c]++;
        
        vector<pair<int, int>> arr;
        for (int i = 0; i < 128; ++i) {
            if (freq[i])
                arr.push_back({freq[i], i});
        }
        sort(arr.rbegin(), arr.rend());
        
        string res;
        for (int i = 0; i < arr.size(); ++i)
            res.append(arr[i].first, arr[i].second);
        return res;
    }
};
