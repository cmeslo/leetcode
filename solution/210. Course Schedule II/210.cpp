class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> degrees(numCourses, 0);
		vector<vector<int>> graph = makeGraph(numCourses, prerequisites, degrees);
		vector<int> visited(numCourses, false);
		queue<int> zeros;
		vector<int> topoSort;


		for (int i = 0; i < numCourses; ++i) {
			if (degrees[i] == 0) {
				zeros.push(i);
			}
		}

		while(!zeros.empty()) {
			int cur = zeros.front();
			zeros.pop();
			topoSort.push_back(cur);

			for (int neigh : graph[cur]) {
				degrees[neigh]--;
				if (degrees[neigh] == 0) {
					zeros.push(neigh);
				}
			}
		}

		for (int i : degrees) {
			if (i != 0) 
				return {};
		}
		return topoSort;
    }
	
private:
    vector<vector<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites, vector<int>& degrees)
    {
    	vector<vector<int>> graph(numCourses, vector<int>(0));
    	for (auto pre : prerequisites) {
    		graph[pre.second].push_back(pre.first);
    		degrees[pre.first]++;
    	}
    	return graph;
    }
};