class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, patched = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patched++;
            }
        }
        return patched;
    }
};

// Example:
// [1, 5, 10], n = 20

// 1, 5, 10
// ^----covered = [0:1), 我下一個想覆蓋到 1，剛好碰到 1，直接延伸現有覆蓋範圍 covered = [0:2)

// 1, 5, 10
//    ^----covered = [0:2), 我下一個想覆蓋到 2，但遇到 5，沒辦法、只能自己添加 patch 了，添加 2
//         covered 範圍由 [0:2) 變成 [0:4)

// 1, 5, 10
//    ^----covered = [0:4), 我下一個想覆蓋到 4，但遇到 5，沒辦法、只能自己添加 patch 了，添加 4
//         covered 範圍由 [0:4) 變成 [0:8)
        
// 1, 5, 10
//    ^----covered = [0:8), 我下一個想覆蓋到 8，遇到 5，直接延伸現有覆蓋範圍 covered = [0:13)

// 1, 5, 10
//       ^----covered = [0:13), 我下一個想覆蓋到 13，遇到 10，直接延伸現有覆蓋範圍 covered = [0:24)，
//            現在覆蓋範圍是 [0:23]，已經覆蓋到 20 了，完。
