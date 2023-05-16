#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[500000];

int binary_search(int target)
{
	int start = 0, end = N - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return 1;
		else if (arr[mid] < target)  start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	cin >> M;
	for (int tmp, i = 0; i < M; i++) {
		cin >> tmp;
		cout << binary_search(tmp) << ' ';
	}
	
	return 0;
}