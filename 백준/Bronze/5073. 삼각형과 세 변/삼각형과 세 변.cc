#include <iostream>
#include <algorithm>
#include <vector>
#define ELIF else if
using namespace std;


bool compare(int n1, int n2) {
	if (n1 < n2)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];

		if (v[0] == v[1] && v[1] == v[2] && v[0] == 0)
			break;

		sort(v.begin(), v.end(), compare);

		if (v[0] + v[1] <= v[2]) cout << "Invalid";
		ELIF(v[0] == v[1] && v[1] == v[2]) cout << "Equilateral";
		ELIF(v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) cout << "Isosceles";
		else cout << "Scalene";

		cout << '\n';
	}

	return 0;
}