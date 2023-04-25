#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct comp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, comp> pq;
	int n; cin >> n;

	while (n--) {
		int temp; cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
			pq.push(temp);
	}
	return 0;
}