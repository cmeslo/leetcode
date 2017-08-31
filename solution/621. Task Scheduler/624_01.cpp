class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0, mxCnt = 0;
		vector<int> taskCnt(26, 0);

		for (auto task : tasks) {
			++taskCnt[task - 'A'];
			if (taskCnt[task - 'A'] == mx) {
				mxCnt++;
			}
			else if (taskCnt[task - 'A'] > mx) {
				mx = taskCnt[task - 'A'];
				mxCnt = 1;
			}
		}

		int partCnt = mx - 1;
		int partLen = n + 1 - mxCnt;
		int emptySlot = partCnt * partLen;
		int taskLeft = tasks.size() - mx * mxCnt;
		int idles = max(0, emptySlot - taskLeft);
		return tasks.size() + idles;
    }
};
