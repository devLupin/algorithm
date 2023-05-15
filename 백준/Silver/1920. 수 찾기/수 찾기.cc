#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int N, M;

int binary_search(int n) 
{
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == n) return 1;
        else if (arr[mid] < n) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int target, i = 0; i < M; i++) {
		cin >> target;
		cout << binary_search(target) << "\n";
	}
}