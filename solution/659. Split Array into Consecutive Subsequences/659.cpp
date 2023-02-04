class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> seq; // 以數字 x 結尾的 sequence 有多少個
        unordered_map<int, int> count; // 數字 x 的剩餘數目
        
        for (int x : nums)
            ++count[x];
        
        for (int x : nums) {
            if (!count[x]) continue;
            
            if (seq[x - 1] > 0) {
                seq[x - 1]--;
                seq[x]++;
                count[x]--;
            } else {
                if (!count[x + 1] || !count[x + 2])
                    return false;
                count[x]--;
                count[x + 1]--;
                count[x + 2]--;
                seq[x + 2]++;
            }
        }
        
        return true;
    }
};


// x 3 x x 4 x 5
//             ^
    
// x x 7 x 8 x x 9 x
//     ^
