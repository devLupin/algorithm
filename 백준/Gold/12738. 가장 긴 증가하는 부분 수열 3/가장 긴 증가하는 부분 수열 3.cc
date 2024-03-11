#include <bits/stdc++.h>
using namespace std;

const int SZ = 1000000;
int N;
vector<int> A, LIS;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> A[i];

	LIS.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (LIS.back() < A[i]) LIS.push_back(A[i]);
		else {
			int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
			LIS[idx] = A[i];
		}
	}

	cout << LIS.size();

	return 0;
}