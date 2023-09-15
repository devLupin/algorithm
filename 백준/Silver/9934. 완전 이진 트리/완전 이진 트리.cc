#include <bits/stdc++.h>
using namespace std;

int in[10024];
int k;
vector<int> arr[10];
void _insert(int d,int s, int e) {
	
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	arr[d].push_back(in[mid]);
	_insert(d + 1, s, mid);
	_insert(d + 1, mid+1, e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> k;
	
	int num;
	int idx = 0;
	while (cin >> num) in[idx++] = num;

	_insert(0,0, idx);
	for (int i = 0; i < k; i++) {
		for (auto o : arr[i]) cout << o << ' ';
		cout << '\n';
	}

	return 0;
}