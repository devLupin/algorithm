#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9];
	for (int i = 0; i < 9; i++) cin >> arr[i];

	cout << *max_element(arr, arr + 9) << '\n' << distance(arr, max_element(arr, arr + 9)) + 1;
}