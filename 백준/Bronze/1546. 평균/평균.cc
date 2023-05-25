#include<bits/stdc++.h>
using namespace std;

int n, arr[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int _max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += (double)arr[i] / _max;

	cout << sum / n * 100;
}