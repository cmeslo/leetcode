class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
		int rCount = 0, dCount = 0;
		for (int i = 0; i < senate.size(); ++i) {
			senate[i] == 'R' ? rCount++ : dCount++;
		}

		while (rCount > 0 && dCount > 0) {
			for (int i = 0; i < senate.size(); ++i) {
				if (senate[i] == 'R') {
					for (int j = i + 1; j < i + n; j++) {
						if (senate[j % n] == 'D') {
							senate[j % n] = 'B';
							dCount--;
							break;
						}
					}
				}
				else if (senate[i] == 'D') {
					for (int j = i + 1; j < i + n; j++) {
						if (senate[j % n] == 'R') {
							senate[j % n] = 'B';
							rCount--;
							break;
						}
					}
				}
			}
		}
		return rCount > dCount ? "Radiant" : "Dire";
    }
};
