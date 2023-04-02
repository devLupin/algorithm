#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int c = 0; c < commands.size(); c++) {
		int i = commands[c][0];
		int j = commands[c][1];
		int k = commands[c][2];

		vector<int> v;

		for (int x = i - 1; x < j; x++)
			v.push_back(array[x]);

		sort(v.begin(), v.end());

		answer.push_back(v[k - 1]);
	}
	return answer;
}