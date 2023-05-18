#include<iostream>
using namespace std;

const int sz = 100002;

int arr[sz], _move[sz], visit[sz];

int search(int start)
{
	int idx = start;
	int cnt = 1;

	while (true) {
		if (_move[idx]) {
			if (start != visit[idx])
				return 0;

			return cnt - _move[idx];
		}
		_move[idx] = cnt++;
		visit[idx] = start;
		idx = arr[idx];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int n, result = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			_move[i] = 0;
			visit[i] = 0;
		}

		for (int i = 1; i <= n; i++)
			if (!_move[i])
				result += search(i);

		cout << n - result << '\n';
	}
	return 0;
}